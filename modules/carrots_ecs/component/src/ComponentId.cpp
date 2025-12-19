#include "component/ComponentId.hpp"


namespace CarrotsEcs
{
    namespace Component
    {
        size_t ComponentId::hash_code() const
        {
            return m_id.hash_code();
        }

        ComponentId::ComponentId(
            std::type_index t_id
        )
        : m_id(t_id)
        {
            
        }
    } // namespace Component
} // namespace CarrotsEcs