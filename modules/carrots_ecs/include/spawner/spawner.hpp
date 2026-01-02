#ifndef CARROTS_ECS_SPAWNER_SPAWNER_HPP_
#define CARROTS_ECS_SPAWNER_SPAWNER_HPP_

#include <tracing.hpp>

#include "archetype/archetype.hpp"
#include "archetype/archetypes.hpp"
#include "entity/entities.hpp"
#include "entity/entity_meta.hpp"
#include "entity/entity.hpp"
#include "table/table_id.hpp"
#include "table/table_row.hpp"
#include "table/table.hpp"
#include "table/tables.hpp"
#include "world/world.hpp"

namespace carrots_ecs
{
    namespace spawner
    {
        MODULE("carrots_ecs::spawner")
        using Archetype = carrots_ecs::archetype::Archetype;
        using Archetypes = carrots_ecs::archetype::Archetypes;
        using Entities = carrots_ecs::entity::Entities;
        using EntityMeta = carrots_ecs::entity::EntityMeta;
        using Entity = carrots_ecs::entity::Entity;
        using TableId = carrots_ecs::table::TableId;
        using TableRow = carrots_ecs::table::TableRow;
        using Table = carrots_ecs::table::Table;
        using Tables = carrots_ecs::table::Tables;
        using World = carrots_ecs::world::World;
        /// A spawner spawns an entity with the given components.
        class Spawner
        {
        public:
            template<typename... Components>
            Spawner(World &t_world, Components... components)
            {
                Archetypes &archetypes = t_world.get_archetypes();
                Tables &tables = t_world.get_tables();
                Entities &entities = t_world.get_entities();
                // Create archetype from components
                Archetype archetype = Archetype::from<Components...>();
                TRACE << "Spawning entity of " << archetype;
                // check if world has archetype and fetch its TableId
                TableId table_id = archetypes
                    .get(archetype)
                    .unwrap_or_else([&]() {
                        // If archetype is new, create a new table
                        TRACE << archetype << " was previously unknown, creating table...";
                        TableId new_table_id = tables.create<Components...>();
                        // add it to the archetypes
                        archetypes.insert(archetype, new_table_id);
                        return new_table_id;
                    });
                // get actual table
                Table &table = tables[table_id];
                // allocate entity
                Entity entity(entities.count());
                // insert it
                TableRow table_row = table.insert(entity, components...);
                // register meta data with world
                entities.set_location(entity, EntityMeta(table_id, table_row));
                TRACE << "Placed " << entity << " in " << table_id << " @ " << table_row;
            }
        };
    } // namespace spawner
} // namespace carrots_ecs


#endif