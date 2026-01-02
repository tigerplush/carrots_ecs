#include "world/world.hpp"

namespace carrots_ecs
{
    namespace world
    {
        bool World::is_empty() const
        {
            return m_entities.is_empty();
        }

        Archetypes &World::get_archetypes()
        {
            return m_archetypes;
        }

        const Archetypes &World::get_archetypes() const
        {
            return m_archetypes;
        }

        Entities &World::get_entities()
        {
            return m_entities;
        }

        const Entities &World::get_entities() const
        {
            return m_entities;
        }

        Tables &World::get_tables()
        {
            return m_tables;
        }

        const Tables &World::get_tables() const
        {
            return m_tables;
        }
    } // namespace World
} // namespace carrots_ecs
