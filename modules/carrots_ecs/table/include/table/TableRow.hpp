#ifndef CARROTS_ECS_TABLE_TABLE_ROW_HPP_
#define CARROTS_ECS_TABLE_TABLE_ROW_HPP_

namespace CarrotsEcs
{
    namespace Table
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
        private:
            size_t m_id;
        };
    } // namespace Table
} // namespace CarrotsEcs

#endif