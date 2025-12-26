#ifndef TRACING_TRACING_HPP_
#define TRACING_TRACING_HPP_

#include "LogLevel.hpp"
#include "LogLine.hpp"

#ifdef TRACING_LOG_MODULE_NAME
constexpr const char* LOG_MODULE_NAME = TRACING_LOG_MODULE_NAME;
#else
constexpr const char* LOG_MODULE_NAME = "";
#endif

#define LOG(severity) Tracing::LogLine(LOG_MODULE_NAME, severity)

#define TRACE LOG(Tracing::LogLevelEnum::Trace)
#define DEBUG LOG(Tracing::LogLevelEnum::Debug)
#define INFO LOG(Tracing::LogLevelEnum::Info)
#define WARNING LOG(Tracing::LogLevelEnum::Warning)
#define ERROR LOG(Tracing::LogLevelEnum::Error)

namespace Tracing
{
    
} // namespace Tracing


#endif