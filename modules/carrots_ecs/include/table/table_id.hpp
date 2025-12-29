#ifndef CARROTS_ECS_TABLE_TABLE_ID_HPP_
#define CARROTS_ECS_TABLE_TABLE_ID_HPP_

#include <ostream>

namespace carrots_ecs
{
    namespace table
    {
        /// An Id for an Table within a World.
        ///
        /// # Remarks
        /// A `TableId` is only unique within a world. If you use a TableId of one World
        /// in another World, it won't produce valid results.
        class TableId
        {
        public:
            TableId(size_t t_id);
            size_t id() const;
        public:
            TableId& operator+=(const size_t &other)
            {
                m_id += other;
                return *this;
            }
            bool operator>(const size_t& other) const
            {
                return m_id > other;
            }
            bool operator>(const TableId& other) const
            {
                return m_id > other.m_id;
            }
            bool operator>=(const size_t& other) const
            {
                return m_id >= other;
            }
            bool operator>=(const TableId& other) const
            {
                return m_id >= other.m_id;
            }
        private:
            friend std::ostream &operator<<(std::ostream &os, const TableId &other)
            {
                os << "TableId (" << other.m_id << ")";
                return os;
            }
        private:
            size_t m_id;
        };
    } // namespace table
} // namespace carrots_ecs

#endif