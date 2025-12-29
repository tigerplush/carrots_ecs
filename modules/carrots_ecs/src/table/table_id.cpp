#include "table/table_id.hpp"

namespace carrots_ecs
{
    namespace table
    {
        TableId::TableId(
            size_t t_id
        )
        : m_id(t_id)
        {

        }

        size_t TableId::id() const
        {
            return m_id;
        }
    } // namespace Table
} // namespace carrots_ecs
