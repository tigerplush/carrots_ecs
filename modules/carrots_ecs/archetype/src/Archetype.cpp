#include "archetype/Archetype.hpp"


namespace CarrotsEcs
{
    namespace Archetype
    {
        Archetype::Archetype(
            std::set<std::type_index> t_signature
        )
        : m_signature(t_signature)
        , m_hash_code(calculate_hash_code())
        {

        }

        size_t Archetype::hash_code() const
        {
            return m_hash_code;
        }

        size_t Archetype::calculate_hash_code() const
        {
            size_t seed = 0;
            for(const std::type_index& type_index: m_signature)
            {
                seed ^= type_index.hash_code() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    } // namespace Archetype
} // namespace CarrotsEcs