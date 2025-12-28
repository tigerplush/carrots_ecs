#include <gtest/gtest.h>
#include "app/App.hpp"

using namespace carrots_app::app;

TEST(AppTest, AppCreate)
{
    EXPECT_EQ(App::create().run(), 0);
}