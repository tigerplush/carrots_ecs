#include "iterator/string_iterator.hpp"

#include "iterator/split.hpp"

namespace carrots_std
{
    namespace iterator
    {
        Split StringIterator::split(std::string delimiter)
        {
            return Split(m_string, delimiter);
        }
    } // namespace Iterator
} // namespace carrots_std