#ifndef CARROTS_ECS_COMPONENT_COMPONENT_ID_HPP_
#define CARROTS_ECS_COMPONENT_COMPONENT_ID_HPP_

#include <typeindex>

namespace CarrotsEcs
{
    namespace Component
    {
        /// An Archetype is a unique combination of Components
        class ComponentId
        {
        public:
            template<typename Component>
            static ComponentId from()
            {
                std::type_index t_id = std::type_index(typeid(Component));
                return ComponentId(t_id);
            }

        public:
            size_t hash_code() const;

        public:
            bool operator==(const ComponentId& other) const
            {
                return m_id == other.m_id;
            }
            bool operator!=(const ComponentId& other) const
            {
                return m_id != other.m_id;
            }

        private:
            explicit ComponentId(std::type_index t_id);
        private:
            std::type_index m_id;
        };
    } // namespace Component
} // namespace CarrotsEcs

#endif