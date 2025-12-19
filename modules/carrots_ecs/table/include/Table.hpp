#ifndef CARROTS_ECS_TABLE_TABLE_HPP_
#define CARROTS_ECS_TABLE_TABLE_HPP_

#include <unordered_map>
#include <vector>

#include "entity/Entity.hpp"

#include "IColumn.hpp"
#include "TableRow.hpp"

namespace CarrotsEcs
{
    namespace Table
    {
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
            std::vector<Entity> m_entities;
            std::vector<IColumn> m_columns;

        private:
            template<typename Component>
            void register_component(Component component)
            {

            }
        };
    } // namespace Table
} // namespace CarrotsEcs

#endif