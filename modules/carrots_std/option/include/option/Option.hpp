#ifndef CARROTS_STD_OPTION_OPTION_HPP_
#define CARROTS_STD_OPTION_OPTION_HPP_

namespace CarrotsStd
{
    namespace Option
    {
        struct NoneType
        {
        public:
            explicit constexpr NoneType() = default;
        };

        inline constexpr NoneType None{};

        template<typename T>
        class Option
        {
        public:
            constexpr Option(NoneType) noexcept
                : m_has_value(false)
                {
                }
            constexpr Option(T t_value)
                : m_has_value(true)
                , m_value(std::move(t_value))
                {
                }
        public:
            bool operator==(const Option<T> &other) const
            {
                bool both_none = is_none() && other.is_none();
                bool both_some = is_some() && other.is_some();
                return both_none || (both_some && (m_value == other.m_value));
            }
            bool operator==(const NoneType &other) const
            {
                return is_none();
            }
            bool operator!=(const Option<T> &other) const
            {
                return !(*this == other);
            }
        public:
            bool is_some() const
            {
                return m_has_value;
            }
            bool is_none() const
            {
                return !is_some();
            }
        private:
            bool m_has_value;
            T m_value;
        };

        template<typename T>
        Option<std::decay_t<T>> Some(T&& value)
        {
            return Option<std::decay_t<T>>(std::forward<T>(value));
        }
    } // namespace Option
} // namespace CarrotsStd


#endif