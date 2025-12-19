#include "Table.hpp"

namespace CarrotsEcs
{
    namespace Table
    {
        const Entity Table::get_entity(TableRow row) const
        {
            return Entity(0);
        }

        void Table::get_component(TableRow row) const
        {

        }

        size_t Table::number_of_components() const
        {
            return m_component_id_to_column_id.size();
        }
    } // namespace Table
} // namespace CarrotsEcs
