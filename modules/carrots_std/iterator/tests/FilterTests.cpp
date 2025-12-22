#include <gtest/gtest.h>

#include "iterator/Filter.hpp"

using namespace CarrotsStd::Iterator;
using namespace CarrotsStd::Option;

class Counter : public Iterator<size_t>
{
public:
    using OutputType = size_t;
    Counter(
        size_t t_from
        , size_t t_to
    )
    : m_from(t_from)
    , m_to(t_to)
    , m_current(m_from)
    {
    }

    Option<OutputType> next() override
    {
        if(m_current >= m_to)
        {
            return None;
        }
        size_t temp = m_current;
        m_current += 1;
        return Option(temp);
    }
private:
    size_t m_from;
    size_t m_to;
    size_t m_current;
};

TEST(FilterTest, FilterIterator)
{
    Counter counter(0, 5);
    size_t index = 0;
    for(auto i: counter.filter([](const size_t & element) { return element % 2 == 0;}))
    {
        EXPECT_EQ(i, index);
        index += 2;
    }
}