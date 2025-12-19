#ifndef CARROTS_ECS_ENTITY_ENTITY_HPP_
#define CARROTS_ECS_ENTITY_ENTITY_HPP_

namespace CarrotsEcs
{
    namespace Entity
    {
        /// An entity is the glue, that holds components together.
        class Entity
        {
        public:
            Entity(size_t t_id);
        public:
            static Entity PLACEHOLDER;
        public:
            bool operator!=(const Entity& other) const
            {
                return m_id != other.m_id;
            }
        private:
            size_t m_id;
        };
    } // namespace Table
} // namespace CarrotsEcs

#endif