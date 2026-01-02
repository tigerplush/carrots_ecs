#include "table/table.hpp"

namespace carrots_ecs
{
    namespace table
    {
        const Entity &Table::get_entity(TableRow row) const
        {
            return m_entities.at(row.id());
        }

        void const *Table::get_component(ComponentId component_id, TableRow row) const
        {
            return get_column(component_id)->at(row);
        }

        size_t Table::entity_count() const
        {
            return m_entities.size();
        }

        size_t Table::component_count() const
        {
            return m_component_id_to_column_id.size();
        }

        const std::unique_ptr<IColumn> &Table::get_column(const ComponentId &component_id) const
        {
            ColumnId column_id = m_component_id_to_column_id.at(component_id);
            std::cout << "IColumn pointer for get: " << m_columns[column_id.id()].get() << std::endl;
            return m_columns.at(column_id.id());
        }
        
        bool Table::contains_component(const ComponentId &component_id) const
        {
            return m_component_id_to_column_id.find(component_id) != m_component_id_to_column_id.end();
        }
    } // namespace Table
} // namespace carrots_ecs
