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
            Archetype()
            {
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

        public:
            const std::set<std::type_index> &get_signature() const;
            /// Returns the precomputed hash of this archetype
            /// @return 
            size_t hash_code() const;
            bool contains(const std::type_index &other) const;

        private:
            explicit Archetype(std::set<std::type_index> t_signature);
            /// Calculates a hash over the signatures by using the stolen formula from boost library `combine_hash`
            /// @return 
            size_t calculate_hash_code() const;
        private:
            std::set<std::type_index> m_signature;
            size_t m_hash_code;
        };
    } // namespace Archetype
} // namespace CarrotsEcs

#endif