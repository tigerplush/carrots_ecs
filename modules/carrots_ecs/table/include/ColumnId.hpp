#ifndef CARROTS_ECS_TABLE_COLUMN_ID_HPP_
#define CARROTS_ECS_TABLE_COLUMN_ID_HPP_

namespace CarrotsEcs
{
    namespace Table
    {
        class ColumnId
        {
        public:
            ColumnId(size_t t_id);
        public:
            size_t id() const;
        private:
            size_t m_id;
        };
    } // namespace Table
} // namespace CarrotsEcs

#endif