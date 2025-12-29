#ifndef CARROTS_ECS_WORLD_ENTITY_META_HPP_
#define CARROTS_ECS_WORLD_ENTITY_META_HPP_

#include "table/table_id.hpp"
#include "table/table_row.hpp"


namespace carrots_ecs
{
    namespace world
    {
        using TableId = carrots_ecs::table::TableId;
        using TableRow = carrots_ecs::table::TableRow;
        class EntityMeta
        {
        public:
            EntityMeta(TableId t_table_id, TableRow t_table_row);
        private:
            TableId m_table_id;
            TableRow m_table_row;
        };
    } // namespace World
} // namespace carrots_ecs

#endif