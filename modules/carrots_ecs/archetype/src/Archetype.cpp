#include "archetype/Archetype.hpp"


namespace CarrotsEcs
{
    namespace Archetype
    {
        Archetype::Archetype(
            std::set<std::type_index> t_signature
        )
        : m_signature(t_signature)
        {

        }
    } // namespace Archetype
} // namespace CarrotsEcs