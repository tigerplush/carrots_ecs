#ifndef CARROTS_ECS_TABLE_I_COLUMN_HPP_
#define CARROTS_ECS_TABLE_I_COLUMN_HPP_

#include "TableRow.hpp"

namespace CarrotsEcs
{
    namespace Table
    {
        /// Type erased interface for a column of component
        class IColumn
        {
        public:
            virtual void* at(TableRow row) = 0;
            virtual const void* at(TableRow row) const = 0;
        };
    } // namespace Table
} // namespace CarrotsEcs

#endif