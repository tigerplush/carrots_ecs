#ifndef CARROTS_ECS_ARCHETYPE_ARCHETYPE_HASHER_HPP_
#define CARROTS_ECS_ARCHETYPE_ARCHETYPE_HASHER_HPP_

#include "Archetype.hpp"

namespace CarrotsEcs
{
    namespace Archetype
    {
        /// A Hasher for Archetypes so Archetypes can be used as Keys in unordered_map's
        ///
        /// Will just return the Archetypes own hash_code
        struct ArchetypeHasher
        {
        public:
            size_t operator()(const Archetype &archetype) const
            {
                return archetype.hash_code();
            }
        };
    } // namespace Archetype
} // namespace CarrotsEcs

#endif
