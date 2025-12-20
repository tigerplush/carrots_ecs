#include "world/EntityMeta.hpp"

namespace CarrotsEcs
{
    namespace World
    {
        EntityMeta::EntityMeta(
            TableId t_table_id
            , TableRow t_table_row
        )
        : m_table_id(t_table_id)
        , m_table_row(t_table_row)
        {
        }
    } // namespace World
} // namespace CarrotsEcs
