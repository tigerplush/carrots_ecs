#ifndef CARROTS_ECS_QUERY_I_QUERY_HPP_
#define CARROTS_ECS_QUERY_I_QUERY_HPP_

namespace CarrotsEcs
{
    namespace Query
    {
        using Table = CarrotsEcs::Table::Table;
        using TableId = CarrotsEcs::Table::TableId;
        /// Type erased interface for queries so the iterator can access
        /// whatever it needs to access.
        class IQuery
        {
        public:
            virtual const size_t table_count() const = 0;
            virtual const size_t row_count(TableId table_id) const = 0;
            virtual const Table &get_table(TableId table_id) const = 0;
        };
    } // namespace Query
} // namespace CarrotsEcs

#endif