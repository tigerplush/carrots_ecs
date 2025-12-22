#include <gtest/gtest.h>
#include "app/App.hpp"

using namespace CarrotsApp::App;

TEST(AppTest, AppCreate)
{
    EXPECT_EQ(App::create().run(), 0);
}