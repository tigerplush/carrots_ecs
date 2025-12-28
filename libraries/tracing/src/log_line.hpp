#ifndef TRACING_LOG_LINE_HPP_
#define TRACING_LOG_LINE_HPP_

#include <sstream>

#include "log_level.hpp"
#include "logger.hpp"

namespace tracing
{
    class LogLine
    {
    public:
        LogLine(const char *t_module, LogLevel t_severity)
        : m_module(t_module)
        , m_severity(t_severity)
        {}
        ~LogLine()
        {
            Logger::get_instance().log(m_module, m_severity, m_stream.str());
        }
    public:
        template<typename T>
        LogLine &operator<<(const T &value)
        {
            m_stream << value;
            return *this;
        }
    private:
        std::ostringstream m_stream;
        const char* m_module;
        LogLevel m_severity;
    };
} // namespace Log

#endif