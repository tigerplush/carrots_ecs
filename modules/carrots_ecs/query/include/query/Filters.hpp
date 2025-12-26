#ifndef CARROTS_ECS_QUERY_FILTERS_HPP_
#define CARROTS_ECS_QUERY_FILTERS_HPP_

namespace CarrotsEcs
{
    namespace Query
    {
        /// This is a marker class to differentiate between
        /// Filters a user wants apply to a query additionally
        /// and the Components a user queries for normally.
        /// @tparam ...Content 
        template<typename... Content>
        class Filters
        {
        };
    } // namespace Query
} // namespace CarrotsEcs


#endif