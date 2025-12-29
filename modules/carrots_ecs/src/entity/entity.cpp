#include "entity/entity.hpp"

#include <stdint.h>

namespace carrots_ecs
{
    namespace entity
    {
        Entity::Entity(
            size_t t_id
        )
        : m_id(t_id)
        , m_generation(0)
        {

        }

        Entity Entity::PLACEHOLDER(SIZE_MAX);

        size_t Entity::id() const
        {
            return m_id;
        }
    } // namespace Entity
} // namespace carrots_ecs
