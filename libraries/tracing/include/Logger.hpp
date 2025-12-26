#ifndef TRACING_LOGGER_HPP_
#define TRACING_LOGGER_HPP_

#include <memory>
#include <string>
#include <vector>

#include "DefaultLogSubscriber.hpp"
#include "ILogSubscriber.hpp"
#include "LogLevel.hpp"

namespace Tracing
{
    class Logger
    {
    public:
        static Logger &get_instance()
        {
            static Logger m_instance;
            return m_instance;
        }
    public:
        void add_subscriber(std::unique_ptr<ILogSubscriber> &&subscriber)
        {
            m_subscribers.push_back(std::move(subscriber));
        }
        void log(const std::string &module, LogLevel severity, const std::string &message)
        {
            if(m_subscribers.empty())
            {
                // if there are no subscribers, log to the default subscriber
                DefaultLogSubscriber::get_instance().log(module, severity, message);
                return;
            }
            for(auto &subscriber: m_subscribers)
            {
                subscriber->log(module, severity, message);
            }
        }
    private:
        std::vector<std::unique_ptr<ILogSubscriber>> m_subscribers;
    };
} // namespace Tracing


#endif