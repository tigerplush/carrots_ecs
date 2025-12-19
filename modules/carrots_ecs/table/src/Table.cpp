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
            return 0;
        }
    } // namespace Table
} // namespace CarrotsEcs
