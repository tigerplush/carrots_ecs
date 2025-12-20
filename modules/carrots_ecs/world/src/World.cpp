#include "world/World.hpp"

namespace CarrotsEcs
{
    namespace World
    {
        bool World::is_empty() const
        {
            return m_archetype_to_table_id.empty();
        }
    } // namespace World
} // namespace CarrotsEcs
