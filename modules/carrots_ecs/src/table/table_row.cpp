#include "table/table_row.hpp"

namespace carrots_ecs
{
    namespace table
    {
        TableRow::TableRow(
            size_t t_id
        )
        : m_id(t_id)
        {

        }

        size_t TableRow::id() const
        {
            return m_id;
        }
    } // namespace Table
} // namespace carrots_ecs
