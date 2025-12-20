#ifndef CARROTS_ECS_WORLD_ENTITY_META_HPP_
#define CARROTS_ECS_WORLD_ENTITY_META_HPP_

#include "table/TableId.hpp"
#include "table/TableRow.hpp"


namespace CarrotsEcs
{
    namespace World
    {
        using TableId = CarrotsEcs::Table::TableId;
        using TableRow = CarrotsEcs::Table::TableRow;
        class EntityMeta
        {
        public:
            EntityMeta(TableId t_table_id, TableRow t_table_row);
        private:
            TableId m_table_id;
            TableRow m_table_row;
        };
    } // namespace World
} // namespace CarrotsEcs

#endif