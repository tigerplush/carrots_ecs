#include <gtest/gtest.h>

#include "iterator/StringIterator.hpp"

using namespace CarrotsStd::Iterator;
using namespace CarrotsStd::Option;

TEST(StringIteratorTests, CreateIterator)
{
    std::string test = "test";
    StringIterator iter(test);
    EXPECT_EQ(iter.next().unwrap(), test);
    EXPECT_EQ(iter.next(), None);
}
