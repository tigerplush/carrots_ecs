#include "world/world.hpp"

namespace carrots_ecs
{
    namespace world
    {
        bool World::is_empty() const
        {
            return m_archetype_to_table_id.empty();
        }

        const std::vector<Table> &World::get_tables() const
        {
            return m_tables;
        }

        const std::unordered_map<Archetype, TableId, ArchetypeHasher> &World::get_archetypes() const
        {
            return m_archetype_to_table_id;
        }
    } // namespace World
} // namespace carrots_ecs
