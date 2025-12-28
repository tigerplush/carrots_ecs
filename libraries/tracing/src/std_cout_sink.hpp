#ifndef TRACING_STD_COUT_SINK_HPP_
#define TRACING_STD_COUT_SINK_HPP_

#include <iostream>
#include <string>

#include "logging_traits.hpp"

namespace tracing
{
    class StdCoutSink : public ILogSink
    {
    public:
        void write(const std::string &message) override
        {
            std::cout << message << std::endl;
        }
    };
} // namespace Tracing


#endif