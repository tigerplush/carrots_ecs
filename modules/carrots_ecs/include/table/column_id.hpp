#ifndef CARROTS_ECS_TABLE_COLUMN_ID_HPP_
#define CARROTS_ECS_TABLE_COLUMN_ID_HPP_

#include <iostream>

namespace carrots_ecs
{
    namespace table
    {
        /// An Id for a column within a table.
        ///
        /// # Remarks
        /// A `ColumnId` is only unique within a table. If you use a ColumnId of one table
        /// in another table, it won't produce valid results.
        class ColumnId
        {
        public:
            /// Creates a new ColumnId with a given id.
            /// @param t_id 
            ColumnId(size_t t_id);
        public:
            /// Returns the id of this ColumnId.
            /// @return 
            size_t id() const;
        private:
            friend std::ostream &operator<<(std::ostream &os, const ColumnId &other)
            {
                os << "ColumnId { " << other.m_id << " }";
                return os;
            }
        private:
            size_t m_id;
        };
    } // namespace table
} // namespace carrots_ecs

#endif