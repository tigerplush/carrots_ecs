#include "iterator/StringIterator.hpp"

#include "iterator/Split.hpp"

namespace CarrotsStd
{
    namespace Iterator
    {
        Split StringIterator::split(std::function<bool(const OutputType&)> f)
        {
            return Split();
        }
    } // namespace Iterator
} // namespace CarrotsStd