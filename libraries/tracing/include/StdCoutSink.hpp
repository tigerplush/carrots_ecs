#ifndef TRACING_STD_COUT_SINK_HPP_
#define TRACING_STD_COUT_SINK_HPP_

#include <iostream>
#include <string>

#include "ILogSink.hpp"

namespace Tracing
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