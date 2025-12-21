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
        // // Iterator helpers
        // private:
        //     /// Struct to discern if a given anonymous type is a filter
        //     /// @tparam ComponentOrFilter 
        //     template<typename ComponentOrFilter>
        //     struct is_filter : std::false_type
        //     {
        //     };

        //     /// Static helper function to check if something is a Component
        //     /// @tparam ComponentOrFilter 
        //     template<typename ComponentOrFilter>
        //     static constexpr bool is_component = !is_filter<ComponentOrFilter>::value;

        //     template<typename... Ignores>
        //     struct extract_components;

        //     /// Helper struct to create an empty tuple type, if no Components have been added to the filter
        //     template<>
        //     struct extract_components<>
        //     {
        //         using type = std::tuple<>;
        //     };

        //     /// Helper struct to extract all components from the template
        //     /// @tparam ComponentOrFilter 
        //     /// @tparam ...Rest 
        //     template<typename ComponentOrFilter, typename... Rest>
        //     struct extract_components<ComponentOrFilter, Rest...>
        //     {
        //         using rest_type = typename extract_components<Rest...>::type;
        //         using type = std::conditional_t<
        //             is_component<ComponentOrFilter>,
        //             decltype(std::tuple_cat(std::declval<std::tuple<ComponentOrFilter>>(), std::declval<rest_type>())),
        //             rest_type
        //         >;
        //     };
        // // Iterator functions
        // public:
        //     using ComponentTuple = typename extract_components<ComponentsOrFilters...>::type;
        public:
            /// Returns an iterator over all tuples
            /// @return 
            QueryIterator<int> iter() const
            {
                return QueryIterator<int>();
            }

        private:
            World &m_world;
            // std::vector<ComponentTuple> m_components;
        };
    } // namespace Query
} // namespace CarrotsEcs

#endif