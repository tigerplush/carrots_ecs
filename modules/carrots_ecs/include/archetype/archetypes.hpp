#ifndef CARROTS_ECS_ARCHETYPE_ARCHETYPES_HPP_
#define CARROTS_ECS_ARCHETYPE_ARCHETYPES_HPP_

#include <unordered_map>

#include <carrots_std.hpp>


#include "archetype_hasher.hpp"
#include "archetype.hpp"
#include "table/table_id.hpp"

namespace carrots_ecs
{
    namespace archetype
    {
        using namespace carrots_std;
        using TableId = carrots_ecs::table::TableId;
        /// This is a collection of Archetype's and their meta data
        class Archetypes
        {
        public:
            bool insert(Archetype archetype, TableId table_id)
            {
                auto it = m_archetype_to_table_id.emplace(archetype, table_id);
                return it.second;
            }
            Option<TableId> get(const Archetype &archetype) const
            {
                if(!m_archetype_to_table_id.contains(archetype))
                {
                    return None;
                }
                return Some(m_archetype_to_table_id.at(archetype));
            }
        public:
            auto begin()
            {
                return m_archetype_to_table_id.begin();
            }
            auto end()
            {
                return m_archetype_to_table_id.end();
            }
        private:
            std::unordered_map<Archetype, TableId, ArchetypeHasher> m_archetype_to_table_id;
        };
    } // namespace archetype
} // namespace carrots_ecs


#endif