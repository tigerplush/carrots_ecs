#ifndef CARROTS_ECS_TABLE_TABLES_HPP_
#define CARROTS_ECS_TABLE_TABLES_HPP_

#include "table_id.hpp"
#include "table.hpp"

namespace carrots_ecs
{
    namespace table
    {
        /// This is a collection of Table's and their MetaData
        class Tables
        {
        public:
            template<typename... Components>
            TableId create()
            {
                Table table = Table::from<Components...>();
                m_tables.emplace_back(std::move(table));
                return TableId(m_tables.size() - 1);
            }
        public:
            Table &operator[](TableId table_id)
            {
                return m_tables[table_id.id()];
            }
        private:
            std::vector<Table> m_tables;
        };
    } // namespace table
} // namespace carrots_ecs

#endif