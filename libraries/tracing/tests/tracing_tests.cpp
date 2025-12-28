#include <gtest/gtest.h>
#include <tracing.hpp>

TEST(TracingTest, Tracing)
{
    TRACE << "This is a Trace";
    DEBUG << "This is a Debug";
    INFO << "This is an Info";
    WARNING << "This is a Warning";
    ERROR << "This is an Error";
}