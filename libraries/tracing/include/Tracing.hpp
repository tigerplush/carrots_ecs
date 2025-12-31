#ifndef TRACING_TRACING_HPP_
#define TRACING_TRACING_HPP_

#include "log_level.hpp"
#include "log_line.hpp"
namespace {
    constexpr const char* TRACING_CURRENT_MODULE = "";
}

#define MODULE(name) \
    namespace { constexpr const char* TRACING_CURRENT_MODULE = name; }

#define LOG(severity) tracing::LogLine(TRACING_CURRENT_MODULE, severity)

#define TRACE LOG(tracing::LogLevelEnum::Trace)
#define DEBUG LOG(tracing::LogLevelEnum::Debug)
#define INFO LOG(tracing::LogLevelEnum::Info)
#define WARNING LOG(tracing::LogLevelEnum::Warning)
#define ERROR LOG(tracing::LogLevelEnum::Error)

namespace tracing
{
    
} // namespace Tracing


#endif