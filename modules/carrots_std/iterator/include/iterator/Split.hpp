#ifndef CARROTS_STD_ITERATOR_SPLIT_HPP_
#define CARROTS_STD_ITERATOR_SPLIT_HPP_

#include "Iterator.hpp"

namespace CarrotsStd
{
    namespace Iterator
    {
        using OutputType = std::string;
        class Split : public Iterator<OutputType>
        {
        public:
            Split()
            {

            }
        public:
            Option::Option<OutputType> next() override
            {
                return Option::None;
            }
        };
    } // namespace Iterator
} // namespace CarrotsStd

#endif