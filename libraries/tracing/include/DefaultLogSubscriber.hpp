#ifndef TRACING_DEFAULT_LOG_SUBSCRIBER_HPP_
#define TRACING_DEFAULT_LOG_SUBSCRIBER_HPP_

#include <assert.h>
#include <chrono>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include <iostream>

#include "ILogSink.hpp"
#include "ILogSubscriber.hpp"
#include "LogLevel.hpp"
#include "StdCoutSink.hpp"

namespace Tracing
{
    class DefaultLogSubscriber : public ILogSubscriber
    {
    public:
        static DefaultLogSubscriber &get_instance()
        {
            static DefaultLogSubscriber m_instance;
            return m_instance;
        }
    public:
        void set_filter(const std::string &filter)
        {
            m_filter.clear();
            if(filter.empty())
            {
                return;
            }
            size_t current_index = 0;
            while (current_index < filter.length())
            {
                size_t next_comma = filter.find(',', current_index);
                size_t length = next_comma == std::string::npos ? filter.length() : next_comma;
                // if next_comma is npos, no comma was found, so we use the remainder
                std::string remainder = filter.substr(current_index, length);

                size_t delimiter_position = remainder.find('=');
                assert(delimiter_position != std::string::npos);
                std::string module_name = remainder.substr(0, delimiter_position);
                std::string log_level = remainder.substr(delimiter_position + 1, remainder.length());
                LogLevel level = LogLevel::parse(log_level);
                m_filter.insert_or_assign(module_name, level);
                current_index += length;
            }
        }

        void log(const std::string &module, LogLevel severity, const std::string &message)
        {
            if(m_sinks.empty() || !should_log(module, severity))
            {
                return;
            }
            std::ostringstream oss;
            oss << timestamp() << " " << std::uppercase << severity << std::nouppercase << " " << module << " " << message;
            for(auto &sink: m_sinks)
            {
                sink->write(oss.str());
            }
        }

        bool should_log(const std::string &module, LogLevel severity)
        {
            // if module is empty, check for usual severity
            if(module.empty())
            {
                return severity >= m_level;
            }

            auto it = m_filter.find(module);
            if(it != m_filter.end())
            {
                return severity >= it->second;
            }
            return false;
        }

        std::string timestamp(const char* format = "%Y-%m-%d %H:%M:%S")
        {
            std::chrono::system_clock::time_point now =std::chrono::system_clock::now();
            std::time_t t = std::chrono::system_clock::to_time_t(now);
            std::chrono::microseconds us = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()) % 1000000;
            std::tm tm;
            localtime_s(&tm, &t);
            char buffer[128];
            std::strftime(buffer, sizeof(buffer), format, &tm);
            std::ostringstream oss;
            oss << buffer << "." << std::setw(6) << std::setfill('0') << us.count() << "Z";
            return oss.str();
        }
    private:
        DefaultLogSubscriber()
        : m_level(LogLevelEnum::Info)
        {
            m_sinks.emplace_back(std::unique_ptr<ILogSink>(new StdCoutSink()));
        }
    private:
        std::vector<std::unique_ptr<ILogSink>> m_sinks;
        LogLevel m_level;
        std::unordered_map<std::string, LogLevel> m_filter;
    };
} // namespace Tracing


#endif