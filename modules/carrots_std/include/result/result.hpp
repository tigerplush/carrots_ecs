#ifndef CARROTS_STD_RESULT_RESULT_HPP_
#define CARROTS_STD_RESULT_RESULT_HPP_

#include <assert.h>
#include <variant>

namespace carrots_std
{
    namespace result
    {
        template<typename T, typename E>
        class Result
        {
        public:
            static Result Ok(T &&value)
            {
                return Result(value, ResultType::Ok);
            }
            static Result Err(E &&error)
            {
                return Result(error, ResultType::Err);
            }
        public:
            bool is_ok() const
            {
                return ResultType::Ok == m_result_type;
            }
            bool is_err() const
            {
                return !is_ok();
            }
        private:
            enum class ResultType
            {
                Ok,
                Err
            };
        private:
            Result(T &&t_value, ResultType t_result_type) : m_result(std::move(t_value)), m_result_type(t_result_type)
            {
            }
            Result(E &&t_error, ResultType t_result_type) : m_result(std::move(t_error)), m_result_type(t_result_type)
            {
            }
        private:
            ResultType m_result_type;
            std::variant<T, E> m_result;
        };
    } // namespace result
} // namespace carrots_std

#endif