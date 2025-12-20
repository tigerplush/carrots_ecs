#include "table/ColumnId.hpp"

namespace CarrotsEcs
{
    namespace Table
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
} // namespace CarrotsEcs
