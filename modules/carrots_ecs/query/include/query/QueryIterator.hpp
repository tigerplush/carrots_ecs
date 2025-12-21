#ifndef CARROTS_ECS_QUERY_QUERY_ITERATOR_HPP_
#define CARROTS_ECS_QUERY_QUERY_ITERATOR_HPP_

#include "CarrotsStd.hpp"

namespace CarrotsEcs
{
    namespace Query
    {
        template<typename OutputType>
        class QueryIterator : public CarrotsStd::Iterator::Iterator<OutputType>
        {
        public:
            CarrotsStd::Option::Option<OutputType> next() override
            {
                return CarrotsStd::Option::None;
            }
        };
    } // namespace Query
} // namespace CarrotsEcs

#endif