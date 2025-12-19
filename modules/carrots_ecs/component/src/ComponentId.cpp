#include "component/ComponentId.hpp"


namespace CarrotsEcs
{
    namespace Component
    {
        ComponentId::ComponentId(
            std::type_index t_id
        )
        : m_id(t_id)
        {
            
        }
    } // namespace Component
} // namespace CarrotsEcs