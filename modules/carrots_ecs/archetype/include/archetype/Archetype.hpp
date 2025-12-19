#ifndef CARROTS_ECS_ARCHETYPE_ARCHETYPE_HPP_
#define CARROTS_ECS_ARCHETYPE_ARCHETYPE_HPP_

#include <set>
#include <typeindex>

namespace CarrotsEcs
{
    namespace Archetype
    {
        /// An Archetype is a unique combination of Components
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
    } // namespace Table
} // namespace CarrotsEcs

#endif