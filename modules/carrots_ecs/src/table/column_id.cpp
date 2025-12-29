#include "table/column_id.hpp"

namespace carrots_ecs
{
    namespace table
    {
        ColumnId::ColumnId(
            size_t t_id
        )
        : m_id(t_id)
        {
        }

        size_t ColumnId::id() const
        {
            return m_id;
        }
    } // namespace Table
} // namespace carrots_ecs
