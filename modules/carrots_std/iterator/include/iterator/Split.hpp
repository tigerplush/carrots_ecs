#ifndef CARROTS_STD_ITERATOR_SPLIT_HPP_
#define CARROTS_STD_ITERATOR_SPLIT_HPP_

#include <string>

#include "Iterator.hpp"

namespace CarrotsStd
{
    namespace Iterator
    {
        using OutputType = std::string;
        class Split : public Iterator<OutputType>
        {
        public:
            Split(
                const std::string &t_string
                , std::string t_delimiter)
                : m_offset(0)
                , m_string(t_string)
                , m_delimiter(t_delimiter)
            {

            }
        public:
            Option::Option<OutputType> next() override
            {
                if(m_offset >= m_string.length())
                {
                    return Option::None;
                }
                size_t pos = m_string.find(m_delimiter, m_offset);
                if(pos == std::string::npos)
                {
                    // No next delimiter, we return the remainder
                    pos = m_string.length();
                }
                std::string substring = m_string.substr(m_offset, pos - m_offset);
                m_offset = pos + m_delimiter.length();
                return Option::Some(std::move(substring));
            }
        private:
            size_t m_offset;
            const std::string &m_string;
            std::string m_delimiter;
        };
    } // namespace Iterator
} // namespace CarrotsStd

#endif