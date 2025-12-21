#ifndef CARROTS_ECS_QUERY_QUERY_ITERATOR_HPP_
#define CARROTS_ECS_QUERY_QUERY_ITERATOR_HPP_

#include "CarrotsStd.hpp"

#include "IQuery.hpp"

namespace CarrotsEcs
{
    namespace Query
    {
        using TableId = CarrotsEcs::Table::TableId;
        using TableRow = CarrotsEcs::Table::TableRow;
        template<typename... OutputType>
        class QueryIterator : public CarrotsStd::Iterator::Iterator<std::tuple<OutputType...>>
        {
        public:
            QueryIterator(std::unique_ptr<IQuery> t_query)
            : m_query(std::move(t_query))
            , m_current_table_id(0)
            , m_current_row(0)
            {

            }
        public:
            CarrotsStd::Option::Option<std::tuple<OutputType...>> next() override
            {
                if(m_current_row > m_query->row_count(m_current_table_id))
                {
                    m_current_table_id += 1;
                    m_current_row = 0;
                }
                if(m_current_table_id > m_query->table_count())
                {
                    return CarrotsStd::Option::None;
                }
                // OutputType temp = m_world->build()?;
                // m_current_row += 1;
                // return Option(temp);
                return CarrotsStd::Option::None;
            }
        private:
            void build_tuple()
            {

            }
        private:
            std::unique_ptr<IQuery> m_query;
            TableId m_current_table_id;
            TableRow m_current_row;
        };
    } // namespace Query
} // namespace CarrotsEcs

#endif