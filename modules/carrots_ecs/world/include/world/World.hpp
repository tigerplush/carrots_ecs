#ifndef CARROTS_ECS_WORLD_WORLD_HPP_
#define CARROTS_ECS_WORLD_WORLD_HPP_

#include <unordered_map>
#include <vector>

#include "archetype/Archetype.hpp"
#include "archetype/ArchetypeHasher.hpp"
#include "entity/Entity.hpp"
#include "table/Table.hpp"
#include "table/TableId.hpp"

#include "EntityMeta.hpp"

namespace CarrotsEcs
{
    namespace World
    {
        using Archetype = CarrotsEcs::Archetype::Archetype;
        using ArchetypeHasher = CarrotsEcs::Archetype::ArchetypeHasher;
        using Entity = CarrotsEcs::Entity::Entity;
        using Table = CarrotsEcs::Table::Table;
        using TableId = CarrotsEcs::Table::TableId;
        using TableRow = CarrotsEcs::Table::TableRow;
        /// A world stores Tables for all Archetypes
        class World
        {
        public:
            /// Spawns an Entity with the given components.
            ///
            /// If no table for the component archetype exists, it will be created (lazy initialisation).
            ///
            /// # Remarks
            ///
            /// I'm not sure about register_table<...>. It checks if there is a table for an archetype already.
            /// We check a second time in this function. I think this could be simplified, have to think about that.
            /// @tparam ...Components
            /// @param ...components
            /// @return
            template <typename... Components>
            Entity spawn(Components... components)
            {
                Archetype archetype = Archetype::from<Components...>();
                if (m_archetype_to_table_id.find(archetype) == m_archetype_to_table_id.end())
                {
                    // No table, register one
                    register_table<Components...>();
                }
                // Now, a table definitely exists
                Entity entity(m_entities.size());
                TableId table_id = m_archetype_to_table_id.at(archetype);
                Table &table = m_tables[table_id.id()];
                TableRow table_row = table.insert(entity, components...);
                m_entities.emplace_back(EntityMeta(table_id, table_row));
                return entity;
            }

            /// Returns if the world is currently empty, meaning it has no Entities.
            /// @return 
            bool is_empty() const;

            const std::vector<Table> &get_tables() const;
            const std::unordered_map<Archetype, TableId, ArchetypeHasher> &get_archetypes() const;

        private:
            std::vector<Table> m_tables;
            std::unordered_map<Archetype, TableId, ArchetypeHasher> m_archetype_to_table_id;
            std::vector<EntityMeta> m_entities;

        private:
            template <typename... Components>
            void register_table()
            {
                Archetype archetype = Archetype::from<Components...>();
                if (m_archetype_to_table_id.find(archetype) == m_archetype_to_table_id.end())
                {
                    TableId table_id(m_archetype_to_table_id.size());
                    m_archetype_to_table_id.emplace(archetype, table_id);
                    Table table = Table::from<Components...>();
                    m_tables.emplace_back(std::move(table));
                    // m_tables.emplace_back(Table::from<Components...>());
                }
            }
        };
    } // namespace World
} // namespace CarrotsEcs

#endif