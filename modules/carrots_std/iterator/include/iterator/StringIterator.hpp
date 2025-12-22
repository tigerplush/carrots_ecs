#ifndef CARROTS_STD_ITERATOR_STRING_ITERATOR_HPP_
#define CARROTS_STD_ITERATOR_STRING_ITERATOR_HPP_

#include <algorithm>
#include <cctype>
#include <functional>
#include <string>

#include "Iterator.hpp"

namespace CarrotsStd
{
    namespace Iterator
    {
        class Split;

        using OutputType = std::string;
        class StringIterator : public Iterator<OutputType>
        {
        public:
            StringIterator(const std::string &t_string)
            : m_exhausted(false)
            , m_string(t_string)
            {
            }
        public:
            std::string to_uppercase()
            {
                std::string uppercase(m_string);
                std::transform(m_string.begin(), m_string.end(), uppercase.begin(),
                       [](unsigned char c)
                       {
                           return std::toupper(c);
                       });
                return uppercase;
            }
            std::string to_lowercase()
            {
                std::string lowercase(m_string);
                std::transform(m_string.begin(), m_string.end(), lowercase.begin(),
                       [](unsigned char c)
                       {
                           return std::tolower(c);
                       });
                return lowercase;
            }
            Split split(std::function<bool(const OutputType&)> f);
        public:
            Option::Option<OutputType> next() override
            {
                if(m_exhausted)
                {
                    return Option::None;
                }
                m_exhausted = true;
                return Option::Some(std::string(m_string));
            }
        private:
            const std::string &m_string;
            bool m_exhausted;
        };
    } // namespace Iterator
} // namespace CarrotsStd

#endif