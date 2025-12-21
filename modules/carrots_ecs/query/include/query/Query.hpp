#ifndef CARROTS_ECS_QUERY_QUERY_HPP_
#define CARROTS_ECS_QUERY_QUERY_HPP_

#include "table/Table.hpp"
#include "world/World.hpp"

#include "Components.hpp"
#include "Filters.hpp"
#include "QueryIterator.hpp"

namespace CarrotsEcs
{
    namespace Query
    {
        template <typename ComponentQuery, typename FilterQuery = Filters<>>
        class Query;

        using Table = CarrotsEcs::Table::Table;
        using World = CarrotsEcs::World::World;
        template<typename... ComponentContent, typename... FilterContent>
        class Query<Components<ComponentContent...>, Filters<FilterContent...>>
        {
        public:
            Query(
                World &t_world
            )
            : m_world(t_world)
            {
                for(const Table& table: m_world.get_tables())
                {
                }
            }
        public:
            size_t count() const
            {
                return iter().count();
            }
        public:
            /// Returns an iterator over all tuples
            /// @return 
            QueryIterator<std::tuple<ComponentContent...>> iter() const
            {
                return QueryIterator<std::tuple<ComponentContent...>>();
            }

        private:
            World &m_world;
            // std::vector<ComponentTuple> m_components;
        };
    } // namespace Query
} // namespace CarrotsEcs

#endif