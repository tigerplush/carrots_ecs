#ifndef TRACING_LOGGING_TRAITS_HPP_
#define TRACING_LOGGING_TRAITS_HPP_

#include <string>

#include "log_level.hpp"

namespace tracing
{
    class ILogSubscriber
    {
    public:
        virtual void log(const std::string &module, LogLevel severity, const std::string &message) = 0;
    };

    class ILogSink
    {
    public:
        virtual ~ILogSink(){}
    public:
        virtual void write(const std::string &message) = 0;
    };
} // namespace tracing


#endif