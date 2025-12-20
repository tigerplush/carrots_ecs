#ifndef CARROTS_ECS_WORLD_WORLD_HPP_
#define CARROTS_ECS_WORLD_WORLD_HPP_

#include <unordered_map>
#include <vector>

#include "archetype/Archetype.hpp"
#include "archetype/ArchetypeHasher.hpp"
#include "table/Table.hpp"
#include "table/TableId.hpp"

namespace CarrotsEcs
{
    namespace World
    {
        using Archetype = CarrotsEcs::Archetype::Archetype;
        using ArchetypeHasher = CarrotsEcs::Archetype::ArchetypeHasher;
        using Table = CarrotsEcs::Table::Table;
        using TableId = CarrotsEcs::Table::TableId;
        /// A world stores Tables for all Archetypes
        class World
        {
        public:
            bool is_empty() const;
        private:
            std::vector<Table> m_tables;
            std::unordered_map<Archetype, TableId, ArchetypeHasher> m_archetype_to_table_id;
        private:
            template<typename... Components>
            void register_table()
            {
                Archetype archetype = Archetype::from<Components...>();
                if(m_archetype_to_table_id.find(archetype) == m_archetype_to_table_id.end())
                {
                    TableId table_id(m_archetype_to_table_id.size());
                    m_archetype_to_table_id.emplace(archetype, table_id);
                    Table table = Table::from<Components...>();
                    m_tables.emplace_back(table);
                }
            }
        };
    } // namespace World
} // namespace CarrotsEcs

#endif