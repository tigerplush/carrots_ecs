#ifndef CARROTS_ECS_TABLE_TABLE_HPP_
#define CARROTS_ECS_TABLE_TABLE_HPP_

#include <memory>
#include <unordered_map>
#include <vector>

#include "component/ComponentId.hpp"
#include "entity/Entity.hpp"

#include "ColumnId.hpp"
#include "Column.hpp"
#include "IColumn.hpp"
#include "TableRow.hpp"

namespace CarrotsEcs
{
    namespace Table
    {
        using ComponentId = CarrotsEcs::Component::ComponentId;
        using Entity = CarrotsEcs::Entity::Entity;
        /// A table saves all entities and their components of a specific archetype
        class Table
        {
        public:
            /// @brief Creates a new table with the given Components
            /// @tparam ...Components 
            /// @param ...components 
            template<typename... Components>
            explicit Table(Components... components)
            {
                (register_component(components), ...);
            }

        public:
            /// @brief Retrieves the entity from the given row
            /// @param row 
            /// @return 
            const Entity get_entity(TableRow row) const;
            /// @brief Retrieves the component from the given row
            /// @param row 
            void get_component(TableRow row) const;
            /// @brief Returns the number of components registered with this table
            /// @return 
            size_t number_of_components() const;

        private:
            struct ComponentIdHasher
            {
                size_t operator()(const ComponentId& component_id) const
                {
                    return component_id.hash_code();
                }
            };
        private:
            std::vector<Entity> m_entities;
            std::unordered_map<ComponentId, ColumnId, ComponentIdHasher> m_component_id_to_column_id;
            std::vector<std::unique_ptr<IColumn>> m_columns;

        private:
            template<typename Component>
            void register_component(Component component)
            {
                ComponentId component_id = ComponentId::from<Component>();
                if(m_component_id_to_column_id.find(component_id) == m_component_id_to_column_id.end())
                {
                    ColumnId column_id(m_component_id_to_column_id.size());
                    m_component_id_to_column_id.emplace(component_id, column_id);
                    std::unique_ptr<Column<Component>> column =  std::make_unique<Column<Component>>();
                    m_columns.push_back(std::move(column));
                }
            }
        };
    } // namespace Table
} // namespace CarrotsEcs

#endif