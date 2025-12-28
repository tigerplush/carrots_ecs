#ifndef CARROTS_STD_RESULT_RESULT_HPP_
#define CARROTS_STD_RESULT_RESULT_HPP_

#include <assert.h>
#include <variant>

namespace carrots_std
{
    namespace result
    {
        struct UnitType
        {};
        template<typename T, typename E>
        class Result;

        template<typename T>
        struct Ok
        {
        public:
            explicit Ok(const T &t_value) : m_value(t_value) {}
            explicit Ok(T &&t_value) : m_value(std::move(t_value)) {}
        private:
            T m_value;
            template<typename U, typename V>
            friend class Result;
        };
        
        template<typename E>
        struct Err
        {
        public:
            explicit Err(const E &t_error) : m_error(t_error) {}
            explicit Err(E &&t_error) : m_error(std::move(t_error)) {}
        private:
            E m_error;
            template<typename U, typename V>
            friend class Result;
        };

        template<typename T, typename E>
        class Result
        {
        public:
            Result(Ok<T> &&ok) : m_result(OkTag{std::move(ok.m_value)})
            {
            }
            Result(Err<E> &&err) : m_result(ErrTag{std::move(err.m_error)})
            {
            }
        public:
            bool is_ok() const
            {
                return std::holds_alternative<OkTag>(m_result);
            }
            bool is_err() const
            {
                return !is_ok();
            }
            T &unwrap()
            {
                assert(is_ok());
                return std::get<OkTag>(m_result).value;
            }
        private:
            struct OkTag
            {
                T value;
            };
            struct ErrTag
            {
                E error;
            };
        private:
            std::variant<OkTag, ErrTag> m_result;
        };
    } // namespace result
} // namespace carrots_std

#endif