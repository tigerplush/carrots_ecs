#include <gtest/gtest.h>

#include "iterator/Iterator.hpp"

using namespace CarrotsStd::Iterator;

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

    std::shared_ptr<OutputType> next() override
    {
        if(m_current >= m_to)
        {
            return nullptr;
        }
        size_t temp = m_current;
        m_current += 1;
        return std::make_shared<size_t>(temp);
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