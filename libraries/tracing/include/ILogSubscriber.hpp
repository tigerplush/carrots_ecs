#ifndef TRACING_I_LOG_SUBSCRIBER_HPP_
#define TRACING_I_LOG_SUBSCRIBER_HPP_

#include <string>

#include "LogLevel.hpp"

namespace Tracing
{
    class ILogSubscriber
    {
    public:
        virtual void log(const std::string &module, LogLevel severity, const std::string &message) = 0;
    };
} // namespace Tracing


#endif