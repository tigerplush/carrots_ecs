#ifndef CARROTS_ECS_TABLE_I_COLUMN_HPP_
#define CARROTS_ECS_TABLE_I_COLUMN_HPP_

#include "table_row.hpp"

namespace carrots_ecs
{
    namespace table
    {
        /// Type erased interface for a column of component
        class IColumn
        {
        public:
            virtual ~IColumn() {}
        public:
            virtual void* at(TableRow row) = 0;
            virtual const void* at(TableRow row) const = 0;
            virtual size_t count() const = 0;
        };
    } // namespace Table
} // namespace carrots_ecs

#endif