#ifndef TRACING_I_LOG_SINK_HPP_
#define TRACING_I_LOG_SINK_HPP_

#include <string>

namespace Tracing
{
    class ILogSink
    {
    public:
        virtual ~ILogSink(){}
    public:
        virtual void write(const std::string &message) = 0;
    };
} // namespace Tracing


#endif