#include <gtest/gtest.h>

#include "iterator/Split.hpp"
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


TEST(StringIteratorTests, Split)
{
    std::string test = "Mary had a little lamb";
    StringIterator iter(test);
    std::vector<std::string> lhs = iter.split(" ").collect<std::vector<std::string>>();
    std::vector<std::string> rhs = { "Mary", "had", "a", "little", "lamb"};
    EXPECT_EQ(lhs, rhs);
}
