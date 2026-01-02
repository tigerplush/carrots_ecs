#ifndef CARROTS_ECS_TABLE_TABLE_HPP_
#define CARROTS_ECS_TABLE_TABLE_HPP_

#include <iostream>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>

#include "component/component_id.hpp"
#include "entity/entity.hpp"

#include "column_id.hpp"
#include "column.hpp"
#include "column_traits.hpp"
#include "table_row.hpp"

namespace carrots_ecs
{
    namespace table
    {
        using ComponentId = carrots_ecs::component::ComponentId;
        using Entity = carrots_ecs::entity::Entity;
        /// A table saves all entities and their components of a specific archetype in columns.
        ///
        /// Visually, you can imagine a table as
        /// | Entities  | Column1   | Column2   | ... | ColumnN    |
        /// |-----------|-----------|-----------|-----|------------|
        /// | Entity(0) | Position0 | Velocity0 | ... | Component0 |
        /// | Entity(1) | Position1 | Velocity1 | ... | Component1 |
        /// | Entity(3) | Position3 | Velocity3 | ... | Component3 |
        ///
        /// If Entities with a different archetype are spawned in between, they will land in another
        /// table, so EntityIds will not be consecutive (and they don't have to be).
        /// The table will ensure, that an Entity in row 0 will have all it's components in row 0 of all the columns.
        class Table
        {
        public:
            /// Creates a new Table holding given Component types.
            /// @tparam ...Components
            /// @return
            template <typename... Components>
            static Table from()
            {
                Table table;
                (table.register_component<Components>(), ...);
                return table;
            }

        public:
            // Disable copy constructor
            Table(const Table &) = delete;
            // Disable copy assignment
            Table &operator=(const Table &) = delete;
            // Enable move constructor
            Table(Table &&) noexcept = default;
            // Enable move assignment
            Table &operator=(Table &&) noexcept = default;

        public:
            /// @brief Inserts an Entity with it's components
            /// @tparam ...Components
            /// @param entity
            /// @param ...components
            /// @return
            template <typename... Components>
            TableRow insert(Entity entity, Components &&...components)
            {
                std::cout << "Trying to insert " << entity << std::endl;
                std::cout << *this << std::endl;
                m_entities.emplace_back(entity);
                TableRow row(m_entities.size() - 1);
                (add_component(std::forward<Components>(components)), ...);
                std::cout << *this << std::endl;
                return row;
            }
            /// @brief Retrieves the entity from the given row
            /// @param row
            /// @return
            const Entity &get_entity(TableRow row) const;

            const std::unique_ptr<IColumn> &get_column(const ComponentId &component_id) const;
            template<typename Component>
            Column<Component> &get_column()
            {
                ComponentId component_id = ComponentId::from<Component>();
                std::cout << "Trying to fetch column for " << component_id;
                ColumnId column_id = m_component_id_to_column_id.at(component_id);
                std::cout << component_id << " has " << column_id << std::endl;
                Column<Component> *column = static_cast<Column<Component> *>(m_columns[column_id.id()].get());
                return *column;
            }

            /// @brief Retrieves a void const ptr to a component from the given column and row
            /// @param row
            void const *get_component(ComponentId component_id, TableRow row) const;
            /// @brief Returns the number of entities in this table.
            /// @return
            size_t entity_count() const;
            /// @brief Returns the number of components registered with this table
            /// @return
            size_t component_count() const;

            /// Returns if this table contains a given ComponentId
            /// @param component_id
            /// @return
            bool contains_component(const ComponentId &component_id) const;

        private:
            explicit Table() {}
            struct ComponentIdHasher
            {
                size_t operator()(const ComponentId &component_id) const
                {
                    return component_id.hash_code();
                }
            };
        private:
            /// Registers a component with the table
            /// @tparam Component 
            template <typename Component>
            void register_component()
            {
                ComponentId component_id = ComponentId::from<Component>();
                std::cout << "Trying to register " << component_id << "..." << std::endl;
                if (m_component_id_to_column_id.find(component_id) == m_component_id_to_column_id.end())
                {
                    std::cout << component_id << " is new, creating a column" << std::endl;
                    ColumnId column_id(m_component_id_to_column_id.size());

                    m_component_id_to_column_id.emplace(component_id, column_id);
                    std::unique_ptr<Column<Component>> column = std::make_unique<Column<Component>>();

                    m_columns.push_back(std::move(column));
                    std::cout << "Added new column with " << column_id << " for " << component_id << std::endl;
                }
            }

            template <typename Component>
            void add_component(Component &&component)
            {
                std::cout << "trying to add " << typeid(Component).name() << std::endl;
                using DecayedComponent = std::decay_t<Component>;
                ComponentId component_id = ComponentId::from<DecayedComponent>();
                ColumnId column_id = m_component_id_to_column_id.at(component_id);
                std::cout << component_id << " has " << column_id << std::endl;
                Column<DecayedComponent> *column = static_cast<Column<DecayedComponent> *>(m_columns[column_id.id()].get());
                std::cout << "inserting into column at " << m_columns[column_id.id()].get() << std::endl;
                column->emplace_back(std::forward<Component>(component));
                std::cout << "inserted into column at " << m_columns[column_id.id()].get() << std::endl;
            }

        private:
            friend std::ostream &operator<<(std::ostream &os, const Table &other)
            {
                os << "Table { ";
                os << "m_entities_count: " << other.m_entities.size();
                os << ", ";
                os << "component_pairs: { ";
                auto it = other.m_component_id_to_column_id.begin();
                for (auto it = other.m_component_id_to_column_id.begin(); it != other.m_component_id_to_column_id.end(); ++it)
                {
                    if (it != other.m_component_id_to_column_id.begin())
                    {
                        os << ", ";
                    }
                    auto [component_id, column_id] = *it;
                    os << "ComponentPair { ";
                    os << component_id;
                    os << ", ";
                    os << column_id;
                    os << " }";
                }
                os << " }, ";
                os << "column_sizes: { ";
                for (size_t index = 0; index < other.m_columns.size(); index++)
                {
                    if (index != 0)
                    {
                        os << ", ";
                    }
                    os << "column " << index << ": " << other.m_columns[index]->count();
                }
                os << "} }";
                return os;
            }

        private:
            std::vector<Entity> m_entities;
            std::unordered_map<ComponentId, ColumnId, ComponentIdHasher> m_component_id_to_column_id;
            std::vector<std::unique_ptr<IColumn>> m_columns;
        };
    } // namespace table
} // namespace carrots_ecs

#endif