#ifndef CARROTS_ECS_QUERY_COMPONENTS_HPP_
#define CARROTS_ECS_QUERY_COMPONENTS_HPP_

namespace carrots_ecs
{
    namespace query
    {
        /// This is a marker class to differentiate between
        /// Components a user wants to query for and Filters
        /// that are applied differently
        /// @tparam ...Content 
        template<typename... Content>
        class Components
        {
        };
    } // namespace query
} // namespace carrots_ecs


#endif