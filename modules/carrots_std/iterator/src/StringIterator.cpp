#include "iterator/StringIterator.hpp"

#include "iterator/Split.hpp"

namespace CarrotsStd
{
    namespace Iterator
    {
        Split StringIterator::split(std::string delimiter)
        {
            return Split(m_string, delimiter);
        }
    } // namespace Iterator
} // namespace CarrotsStd