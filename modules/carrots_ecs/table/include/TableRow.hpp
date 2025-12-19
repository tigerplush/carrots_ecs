#ifndef CARROTS_ECS_TABLE_TABLE_ROW_HPP_
#define CARROTS_ECS_TABLE_TABLE_ROW_HPP_

namespace CarrotsEcs
{
    namespace Table
    {
        /// A table saves all entities and their components of a specific archetype
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