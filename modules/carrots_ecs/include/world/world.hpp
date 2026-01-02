#ifndef CARROTS_ECS_WORLD_WORLD_HPP_
#define CARROTS_ECS_WORLD_WORLD_HPP_

#include <unordered_map>
#include <vector>

#include <tracing.hpp>

#include "archetype/archetypes.hpp"
#include "entity/entities.hpp"
#include "table/tables.hpp"

namespace carrots_ecs
{
    namespace world
    {
        MODULE("carrots_ecs::world")
        using Archetypes = carrots_ecs::archetype::Archetypes;
        using Entities = carrots_ecs::entity::Entities;
        using Tables = carrots_ecs::table::Tables;
        /// A World is the central storage for everything.
        ///
        /// This class should only hold data and manage it. It is not responsible
        /// for creating and removing entities, components, etc.
        class World
        {
        public:
            /// Returns if the world is currently empty, meaning it has no Entities.
            /// @return 
            bool is_empty() const;

            Archetypes &get_archetypes();
            const Archetypes &get_archetypes() const;

            Entities &get_entities();
            const Entities &get_entities() const;

            Tables &get_tables();
            const Tables &get_tables() const;
        private:
            Archetypes m_archetypes;
            Entities m_entities;
            Tables m_tables;
        };
    } // namespace World
} // namespace carrots_ecs

#endif