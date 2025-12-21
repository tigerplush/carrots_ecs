#include <gtest/gtest.h>

#include "iterator/Iterator.hpp"

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

TEST(IteratorTest, CreateIterator)
{
    Counter counter(0, 5);
    size_t i = 0;
    for(const size_t& index: counter)
    {
        EXPECT_EQ(index, i);
        i += 1;
    }
}

TEST(IteratorTest, IteratorNext)
{
    Counter counter(0, 5);
    EXPECT_EQ(counter.next(), Some(0ull));
    EXPECT_EQ(counter.next(), Some(1ull));
    EXPECT_EQ(counter.next(), Some(2ull));
    EXPECT_EQ(counter.next(), Some(3ull));
    EXPECT_EQ(counter.next(), Some(4ull));
    EXPECT_EQ(counter.next(), None);
}

TEST(IteratorTest, CountIterator)
{
    Counter counter(0, 5);
    EXPECT_EQ(counter.count(), 5);
}

TEST(IteratorTest, FoldIterator)
{
    Counter counter(0, 5);
    EXPECT_EQ(counter.fold<size_t>(0, [](size_t acc, const Counter::OutputType &element) {
        acc += 1;
        return acc;
    }), 5);
}