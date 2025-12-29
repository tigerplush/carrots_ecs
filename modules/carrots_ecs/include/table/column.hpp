#ifndef CARROTS_ECS_TABLE_COLUMN_HPP_
#define CARROTS_ECS_TABLE_COLUMN_HPP_

#include <vector>

#include "column_traits.hpp"

namespace carrots_ecs
{
    namespace table
    {
        /// A column stores all instances of one component.
        /// @tparam Component Component type to store
        template <typename Component>
        class Column : public IColumn
        {
        public:
            /// Retrieves a void ptr to a component from the given row.
            /// @param row 
            /// @return 
            void* at(TableRow row) override
            {
                return &m_components[row.id()];
            }
            /// Retrieves a const void ptr to a component from the given row
            /// @param row 
            /// @return 
            const void* at(TableRow row) const override
            {
                return &m_components[row.id()];
            }

            /// Pushes a given component to the end of the column
            /// @param component 
            void emplace_back(Component component)
            {
                m_components.emplace_back(component);
            }

        private:
            std::vector<Component> m_components;
        };
    } // namespace table
} // namespace carrots_ecs

#endif