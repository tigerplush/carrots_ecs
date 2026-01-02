#ifndef CARROTS_ECS_ENTITY_ENTITIES_HPP_
#define CARROTS_ECS_ENTITY_ENTITIES_HPP_

#include <vector>

#include "entity_meta.hpp"
#include "entity.hpp"

namespace carrots_ecs
{
    namespace entity
    {
        /// An Entity represents an object in the World.
        class Entities
        {
        public:
            void set_location(Entity entity, EntityMeta location)
            {
                if(count() <= entity.id())
                {
                    // not enough entities, something went wrong
                    m_meta.resize(entity.id() + 1);
                }
                m_meta[entity.id()] = location;
            }

            bool is_empty() const
            {
                return m_meta.empty();
            }

            size_t count() const
            {
                return m_meta.size();
            }
        private:
            std::vector<EntityMeta> m_meta;
        };
    } // namespace entity
} // namespace carrots_ecs

#endif