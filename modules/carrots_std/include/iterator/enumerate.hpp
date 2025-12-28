#ifndef CARROTS_STD_ITERATOR_ENUMERATE_HPP_
#define CARROTS_STD_ITERATOR_ENUMERATE_HPP_

#include "iterator.hpp"

namespace carrots_std
{
    namespace iterator
    {
        template<typename T>
        using Indexed = std::tuple<size_t, T>;

        /// An iterator that yields the current count and the element during iteration.
        /// This iterator is created by the `.enumerate()` method on `Iterator`
        /// @tparam OutputType 
        template<typename OutputType>
        class Enumerate : public Iterator<Indexed<OutputType>>
        {
        public:
            using Item = Indexed<OutputType>;
        public:
            Enumerate(
                Iterator<OutputType>*t_iter
            )
            : m_iter(t_iter)
            , m_index(0)
            {}
        public:
            Option<Item> next() override
            {
                Option<OutputType> next = m_iter->next();
                if(next.is_none())
                {
                    return None;
                }
                size_t index = m_index;
                m_index += 1;
                return Some(Item{index, next.unwrap()});
            }

        private:
            Iterator<OutputType> *m_iter;
            size_t m_index;
        };
    } // namespace iterator
} // namespace carrots_std


#endif