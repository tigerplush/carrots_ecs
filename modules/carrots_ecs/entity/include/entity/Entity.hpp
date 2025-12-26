#ifndef CARROTS_ECS_ENTITY_ENTITY_HPP_
#define CARROTS_ECS_ENTITY_ENTITY_HPP_

#include <ostream>

namespace CarrotsEcs
{
    namespace Entity
    {
        /// An Entity represents an object in the World.
        class Entity
        {
        public:
            Entity(size_t t_id);
        public:
            static Entity PLACEHOLDER;
        public:
            size_t id() const;
        public:
            bool operator!=(const Entity& other) const
            {
                return m_id != other.m_id;
            }
        private:
            friend std::ostream &operator<<(std::ostream &os, const Entity &other)
            {
                os << "Entity (" << other.m_id << "v" << other.m_generation << ")";
                return os;
            }
        private:
            size_t m_id;
            size_t m_generation;
        };
    } // namespace Entity
} // namespace CarrotsEcs

#endif