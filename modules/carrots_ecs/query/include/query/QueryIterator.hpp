#ifndef CARROTS_ECS_QUERY_QUERY_ITERATOR_HPP_
#define CARROTS_ECS_QUERY_QUERY_ITERATOR_HPP_

#include "CarrotsStd.hpp"

#include "IQuery.hpp"

namespace CarrotsEcs
{
    namespace Query
    {
        using ComponentId = CarrotsEcs::Component::ComponentId;
        using Entity = CarrotsEcs::Entity::Entity;
        using TableId = CarrotsEcs::Table::TableId;
        using TableRow = CarrotsEcs::Table::TableRow;
        template <typename... Components>
        class QueryIterator : public CarrotsStd::Iterator::Iterator<std::tuple<Components...>>
        {
        public:
            QueryIterator(std::unique_ptr<IQuery> t_query)
                : m_query(std::move(t_query)), m_current_table_id(0), m_current_row(0)
            {
            }

        public:
            CarrotsStd::Option::Option<std::tuple<Components...>> next() override
            {
                if (m_current_row >= m_query->row_count(m_current_table_id))
                {
                    m_current_table_id += 1;
                    m_current_row = 0;
                }
                if (m_current_table_id >= m_query->table_count())
                {
                    return CarrotsStd::Option::None;
                }
                std::tuple<Components...> current_tuple = build_tuple();
                m_current_row += 1;
                return CarrotsStd::Option::Some(std::move(current_tuple));
            }

        private:
            std::tuple<Components...> build_tuple()
            {
                // for every component:
                // fetch component from current table and id
                // pack then in tuple
                std::tuple<Components...> current_tuple = {fetch_entity_or_component<Components>()...};
                return current_tuple;
            }
            template <typename EntityOrComponent>
            EntityOrComponent fetch_entity_or_component()
            {
                using BaseType = std::remove_cvref_t<EntityOrComponent>;

                if constexpr (std::is_same_v<BaseType, Entity>)
                {
                    return fetch_entity<EntityOrComponent>();
                }
                else
                {
                    return fetch_component<EntityOrComponent>();
                }
            }

            template <typename Component>
            Component fetch_component()
            {
                ComponentId component_id = ComponentId::from<std::remove_cvref_t<Component>>();
                void *component_ptr = m_query
                    ->get_table(m_current_table_id)
                    .get_column(component_id)
                    ->at(m_current_row);
                using BaseType = std::remove_reference_t<Component>;
                return *reinterpret_cast<BaseType *>(component_ptr);
            }
            template <typename EntityType>
            EntityType fetch_entity()
            {
                return m_query
                    ->get_table(m_current_table_id)
                    .get_entity(m_current_row);
            }

        private:
            std::unique_ptr<IQuery> m_query;
            TableId m_current_table_id;
            TableRow m_current_row;
        };
    } // namespace Query
} // namespace CarrotsEcs

#endif