#include "TableRow.hpp"

namespace CarrotsEcs
{
    namespace Table
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
} // namespace CarrotsEcs
