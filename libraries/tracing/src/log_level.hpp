#ifndef TRACING_LOG_LEVEL_HPP_
#define TRACING_LOG_LEVEL_HPP_

#include <algorithm>
#include <assert.h>
#include <ostream>

namespace tracing
{
    enum class LogLevelEnum
    {
        Trace,
        Debug,
        Info,
        Warning,
        Error
    };

    class LogLevel
    {
    public:
        static LogLevel parse(const std::string &string)
        {
            if("TRACE" == string)
            {
                return LogLevel(LogLevelEnum::Trace);
            }
            if("DEBUG" == string)
            {
                return LogLevel(LogLevelEnum::Debug);
            }
            if("INFO" == string)
            {
                return LogLevel(LogLevelEnum::Info);
            }
            if("WARNING" == string)
            {
                return LogLevel(LogLevelEnum::Warning);
            }
            if("ERROR" == string)
            {
                return LogLevel(LogLevelEnum::Error);
            }
            assert(true);
        }
    public:
        LogLevel() = delete;
        LogLevel(LogLevelEnum t_enum) : m_enum(t_enum) {}
    public:
        bool operator>=(const LogLevel &other)
        {
            return m_enum >= other.m_enum;
        }
    private:
        friend std::ostream &operator<<(std::ostream &os, const LogLevel &other)
        {
            std::string level;
            switch (other.m_enum)
            {
            case LogLevelEnum::Trace:
                level = "Trace";
                break;
            case LogLevelEnum::Debug:
                level = "Debug";
                break;
            case LogLevelEnum::Info:
                level = "Info";
                break;
            case LogLevelEnum::Warning:
                level = "Warning";
                break;
            case LogLevelEnum::Error:
                level = "Error";
                break;
            }
            if(os.flags() & std::ios_base::uppercase)
            {
                std::transform(
                    level.begin(),
                    level.end(),
                    level.begin(),
                    [](unsigned char c)
                    {
                        return std::toupper(c);
                    }
                );
            }
            os << level;
            return os;
        }
    private:
        LogLevelEnum m_enum;
    };
} // namespace Log

#endif