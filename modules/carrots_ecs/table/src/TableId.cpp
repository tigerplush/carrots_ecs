#include "table/TableId.hpp"

namespace CarrotsEcs
{
    namespace Table
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
} // namespace CarrotsEcs
