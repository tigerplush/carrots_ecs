#ifndef CARROTS_ECS_ARCHETYPE_ARCHETYPE_HPP_
#define CARROTS_ECS_ARCHETYPE_ARCHETYPE_HPP_

#include <set>
#include <typeindex>

namespace CarrotsEcs
{
    namespace Archetype
    {
        /// An Archetype is a unique combination of Component signatures.
        ///
        /// `Archetype::from<Position>()` would create different Archetype to `Archetype::from<Velocity>()`,
        /// but `Archetype::from<Position, Velocity>()` would produce the same Archetype as `Archetype::from<Velocity, Position>()`.
        class Archetype
        {
        public:
            template<typename... Components>
            static Archetype from()
            {
                std::set<std::type_index> t_signature = {std::type_index(typeid(Components))...};
                return Archetype(t_signature);
            }

        public:
            bool operator==(const Archetype& other) const
            {
                return m_signature == other.m_signature;
            }
            bool operator!=(const Archetype& other) const
            {
                return m_signature != other.m_signature;
            }

        private:
            explicit Archetype(std::set<std::type_index> t_signature);
        private:
            std::set<std::type_index> m_signature;
        };
    } // namespace Archetype
} // namespace CarrotsEcs

#endif