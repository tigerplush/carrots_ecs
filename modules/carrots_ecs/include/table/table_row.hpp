#ifndef CARROTS_ECS_TABLE_TABLE_ROW_HPP_
#define CARROTS_ECS_TABLE_TABLE_ROW_HPP_

#include <ostream>

namespace carrots_ecs
{
    namespace table
    {
        /// An Id for an Entity within a table.
        ///
        /// # Remarks
        /// A `TableRow` is only unique within a table. If you use a TableRow of one table
        /// in another table, it won't produce valid results.
        class TableRow
        {
        public:
            TableRow(size_t t_id);
            size_t id() const;
        public:
            TableRow& operator+=(const size_t &other)
            {
                m_id += other;
                return *this;
            }
            bool operator>(const size_t& other) const
            {
                return m_id > other;
            }
            bool operator>(const TableRow& other) const
            {
                return m_id > other.m_id;
            }
            bool operator>=(const size_t& other) const
            {
                return m_id >= other;
            }
            bool operator>=(const TableRow& other) const
            {
                return m_id >= other.m_id;
            }
        private:
            friend std::ostream &operator<<(std::ostream &os, const TableRow &other)
            {
                os << "TableRow(" << other.m_id << ")";
                return os;
            }
        private:
            size_t m_id;
        };
    } // namespace table
} // namespace carrots_ecs

#endif