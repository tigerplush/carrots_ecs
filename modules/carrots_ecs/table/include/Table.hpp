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
            template<typename... Components>
            explicit Table(Components... components)
            {

            }

        public:
            const Entity get_entity(TableRow row) const;
            void get_component(TableRow row) const;
            size_t number_of_components() const;

        private:
            std::vector<Entity> m_entities;
            std::vector<IColumn> m_columns;

        private:
        };
    } // namespace Table
} // namespace CarrotsEcs

#endif