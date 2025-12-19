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
        template <typename Component>
        class Column : public IColumn
        {
        public:
            void* at(TableRow row) override
            {
                return &m_components[row.id()];
            }
            const void* at(TableRow row) const override
            {
                return &m_components[row.id()];
            }

            void emplace_back(Component component)
            {
                m_components.emplace_back(component);
            }

        private:
            std::vector<Component> m_components;
        };
    } // namespace Table
} // namespace CarrotsEcs

#endif