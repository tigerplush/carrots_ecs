#ifndef CARROTS_STD_ITERATOR_FILTER_HPP_
#define CARROTS_STD_ITERATOR_FILTER_HPP_

#include "Iterator.hpp"

namespace CarrotsStd
{
    namespace Iterator
    {
        template<typename OutputType>
        class Filter : public Iterator<OutputType>
        {
        public:
            Filter(
                Iterator<OutputType>*t_iter
                , std::function<bool(const OutputType&)> t_predicate
            )
            : m_iter(t_iter)
            , m_predicate(t_predicate)
            {}
        public:
            Option::Option<OutputType> next() override
            {
                return m_iter->find(m_predicate);
            }

        private:
            Iterator<OutputType> *m_iter;
            std::function<bool(const OutputType&)> m_predicate;
        };
    } // namespace Iterator
} // namespace CarrotsStd


#endif