#include "entity/entity_meta.hpp"

namespace carrots_ecs
{
    namespace entity
    {
        EntityMeta::EntityMeta() : m_table_id(None), m_table_row(None)
        {
            
        }

        EntityMeta::EntityMeta(
            TableId t_table_id
            , TableRow t_table_row
        )
        : m_table_id(t_table_id)
        , m_table_row(t_table_row)
        {
        }
    } // namespace World
} // namespace carrots_ecs
