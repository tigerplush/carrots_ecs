#ifndef CARROTS_STD_ITERATOR_STRING_ITERATOR_HPP_
#define CARROTS_STD_ITERATOR_STRING_ITERATOR_HPP_

#include <algorithm>
#include <cctype>
#include <functional>
#include <string>

#include "iterator.hpp"

namespace carrots_std
{
    namespace iterator
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
            explicit StringIterator(std::string &&str) = delete;
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
            Split split(std::string delimiter);
        public:
            Option<OutputType> next() override
            {
                if(m_exhausted)
                {
                    return None;
                }
                m_exhausted = true;
                return Some(std::string(m_string));
            }
        private:
            const std::string &m_string;
            bool m_exhausted;
        };
    } // namespace iterator
} // namespace carrots_std

#endif