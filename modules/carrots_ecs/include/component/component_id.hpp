#ifndef CARROTS_ECS_COMPONENT_COMPONENT_ID_HPP_
#define CARROTS_ECS_COMPONENT_COMPONENT_ID_HPP_

#include <iostream>
#include <typeindex>

namespace carrots_ecs
{
    namespace component
    {
        /// A ComponentId is a unique signature of a component.
        ///
        /// `ComponentId::from<Velocity>()` will create a different ComponentId from `ComponentId::from<Position>()`.
        class ComponentId
        {
        public:
            template <typename Component>
            static ComponentId from()
            {
                std::type_index t_id = std::type_index(typeid(Component));
                return ComponentId(t_id);
            }

        public:
            size_t hash_code() const;

        public:
            bool operator==(const ComponentId &other) const
            {
                return m_id == other.m_id;
            }
            bool operator!=(const ComponentId &other) const
            {
                return m_id != other.m_id;
            }

        private:
            explicit ComponentId(std::type_index t_id);

        private:
            friend std::ostream &operator<<(std::ostream &os, const ComponentId &other)
            {
                os << "ComponentId { " << other.m_id.name() << ", hash_code: " << other.m_id.hash_code() << " }";
                return os;
            }

        private:
            std::type_index m_id;
        };
    } // namespace component
} // namespace carrots_ecs

#endif