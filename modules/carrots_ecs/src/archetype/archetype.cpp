#include "archetype/archetype.hpp"


namespace carrots_ecs
{
    namespace archetype
    {
        Archetype::Archetype(
            std::set<std::type_index> t_signature
        )
        : m_signature(t_signature)
        , m_hash_code(calculate_hash_code())
        {

        }

        const std::set<std::type_index> &Archetype::get_signature() const
        {
            return m_signature;
        }

        size_t Archetype::hash_code() const
        {
            return m_hash_code;
        }

        bool Archetype::contains(const std::type_index &other) const
        {
            return m_signature.find(other) != m_signature.end();
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
} // namespace carrots_ecs