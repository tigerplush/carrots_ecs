#ifndef CARROTS_STD_ITERATOR_ITERATOR_HPP_
#define CARROTS_STD_ITERATOR_ITERATOR_HPP_

#include <functional>

#include "option/Option.hpp"

namespace CarrotsStd
{
    namespace Iterator
    {
        // Forward declaration of Filter
        template<typename OutputType>
        class Filter;
        /// Iterator class to iterate over a collection of items.
        ///
        /// Iterator is lazily evaluated, which means there doesn't have to
        /// be a known fixed size beforehand. Keep in mind that iterators are
        /// stateful, so they can be consumed.
        ///
        /// # Remarks
        ///
        /// It is strongly recommended not to implement this for any class you want to
        /// iterate over. Rather you should implement this for an Iterator class, e.g.
        /// you want to iterate over values of a `class Range`, then implement this
        /// Iterator for `class RangeIterator` and return `RangeIterator` from `iter()` because
        /// traversing an iterator consumes it and calling `.count()` and then iterating over
        /// the same iterator would lead to empty results.
        /// @tparam OutputType 
        template<typename OutputType>
        class Iterator
        {
        public:
            struct iterator
            {
            public:
                /// Creates an empty iterator that will serve es `.end()`
                iterator()
                : m_iter(nullptr)
                , m_end(true)
                , m_value(Option::None)
                {
                }

                /// Creates an iterator from it's parent class
                /// @param t_iter 
                iterator(
                    Iterator<OutputType> *t_iter
                )
                : m_iter(t_iter)
                , m_end(false)
                , m_value(Option::None)
                {
                    advance();
                }

            public:
                OutputType operator*()
                {
                    return m_value.unwrap();
                }
                iterator &operator++()
                {
                    advance();
                    return *this;
                }
                bool operator==(iterator& other) const
                {
                    return m_end == other.m_end;
                }
                bool operator!=(iterator& other) const
                {
                    return !(*this == other);
                }
            private:
                Iterator<OutputType> *m_iter;
                bool m_end;
                Option::Option<OutputType> m_value;
            private:
                void advance()
                {
                    if(nullptr == m_iter)
                    {
                        m_end = true;
                        return;
                    }

                    m_value = m_iter->next();
                    m_end = (Option::None == m_value);
                }
            };
        public:
            iterator begin()
            {
                return iterator(this);
            }
            iterator end()
            {
                return iterator();
            }
        public:
            /// Folds every element into an accumulator by applying an operation, returning the final result.
            /// @tparam B 
            /// @param init 
            /// @param f 
            /// @return 
            template<typename B>
            B fold(B init, std::function<B(B, const OutputType&)> f)
            {
                B accumulator = init;
                Option::Option<OutputType> x = next();
                while(Option::None != x)
                {
                    accumulator = f(accumulator, x.unwrap());
                    x = next();
                }
                return accumulator;
            }


            /// Finds the first element in the iterator that matches the predicate
            /// @param f 
            /// @return Option of element, None if no element could be found
            Option::Option<OutputType> find(std::function<bool(const OutputType&)> f)
            {
                Option::Option<OutputType> x = next();
                while(Option::None != x)
                {
                    if(f(x.unwrap()))
                    {
                        return x;
                    }
                    x = next();
                }
                return Option::None;
            }

            /// Filters an iterator after a predicate and returns an iterator to the filtered values.
            /// This filtered iterator is lazily evaluated and consumes it's parent.
            /// @param f 
            /// @return 
            Filter<OutputType> filter(std::function<bool(const OutputType&)> f)
            {
                return Filter<OutputType>(this, f);
            }

            /// Counts the number of elements in this iterator, thus
            /// consuming it.
            /// @return 
            size_t count()
            {
                return fold<size_t>(0, [](size_t count, OutputType) {
                    count += 1;
                    return count;
                });
            }
        public:
            virtual Option::Option<OutputType> next() = 0;
        };
    } // namespace Iterator
} // namespace CarrotsStd

#endif