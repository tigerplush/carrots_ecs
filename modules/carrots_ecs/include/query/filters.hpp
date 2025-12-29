#ifndef CARROTS_ECS_QUERY_FILTERS_HPP_
#define CARROTS_ECS_QUERY_FILTERS_HPP_

namespace carrots_ecs
{
    namespace query
    {
        /// This is a marker class to differentiate between
        /// Filters a user wants apply to a query additionally
        /// and the Components a user queries for normally.
        /// @tparam ...Content 
        template<typename... Content>
        class Filters
        {
        };
    } // namespace query
} // namespace carrots_ecs


#endif