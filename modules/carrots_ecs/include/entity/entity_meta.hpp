#ifndef CARROTS_ECS_ENTITY_ENTITY_META_HPP_
#define CARROTS_ECS_ENTITY_ENTITY_META_HPP_

#include <carrots_std.hpp>

#include "table/table_id.hpp"
#include "table/table_row.hpp"


namespace carrots_ecs
{
    namespace entity
    {
        using namespace carrots_std;
        using TableId = carrots_ecs::table::TableId;
        using TableRow = carrots_ecs::table::TableRow;
        class EntityMeta
        {
        public:
            EntityMeta();
            EntityMeta(TableId t_table_id, TableRow t_table_row);
        private:
            Option<TableId> m_table_id;
            Option<TableRow> m_table_row;
        };
    } // namespace World
} // namespace carrots_ecs

#endif