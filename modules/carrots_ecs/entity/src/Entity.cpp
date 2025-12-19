#include "entity/Entity.hpp"

#include <stdint.h>

namespace CarrotsEcs
{
    namespace Entity
    {
        Entity::Entity(
            size_t t_id
        )
        : m_id(t_id)
        {

        }

        Entity Entity::PLACEHOLDER(SIZE_MAX);
    } // namespace Table
} // namespace CarrotsEcs
