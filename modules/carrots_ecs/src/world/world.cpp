#include "world/world.hpp"

namespace carrots_ecs
{
    namespace world
    {
        bool World::is_empty() const
        {
            return m_entities.empty();
        }

        const std::vector<Table> &World::get_tables() const
        {
            return m_tables;
        }

        const std::unordered_map<Archetype, TableId, ArchetypeHasher> &World::get_archetypes() const
        {
            return m_archetype_to_table_id;
        }

        void World::add_schedule(Schedule schedule)
        {
            // get a mutable reference to Schedules
            // if it doesn't exist, spawn it
            // add the given schedule
        }

        void World::run_schedule(ScheduleLabel label)
        {
            // get a mutable reference to Schedules
            // remove the current schedule
            // run the current schedule
            // add it back in
        }
    } // namespace World
} // namespace carrots_ecs
