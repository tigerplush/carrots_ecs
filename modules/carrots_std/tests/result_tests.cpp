#include <gtest/gtest.h>

#include <carrots_std.hpp>

using namespace carrots_std;

TEST(ResultTests, ResultOk)
{
    Result<int, int> ok = Ok(5);
    EXPECT_TRUE(ok.is_ok());
    EXPECT_FALSE(ok.is_err());
}

TEST(ResultTests, ResultErr)
{
    Result<int, int> err = Err(5);
    EXPECT_TRUE(err.is_err());
    EXPECT_FALSE(err.is_ok());
}