#ifndef CARROTS_ECS_TABLE_COLUMN_HPP_
#define CARROTS_ECS_TABLE_COLUMN_HPP_

#include <vector>

#include "IColumn.hpp"

namespace CarrotsEcs
{
    namespace Table
    {
        /// A column saves all instances of a component
        /// @tparam Component 
        template<typename Component>
        class Column : public IColumn
        {
        public:
        private:
            std::vector<Component> m_components;
        };
    } // namespace Table
} // namespace CarrotsEcs

#endif