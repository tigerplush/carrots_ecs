#ifndef CARROTS_STD_OPTION_OPTION_HPP_
#define CARROTS_STD_OPTION_OPTION_HPP_

#include <type_traits>

namespace carrots_std
{
    namespace option
    {
        struct NoneType
        {
        public:
            explicit constexpr NoneType() = default;
        };

        inline constexpr NoneType None{};

        /// Represents an optional value.
        ///
        /// Optional values either are Some(value) or None.
        /// @tparam T
        template <typename T>
        class Option
        {
        private:
            // Use pointer storage for references, direct storage for non-references
            using StorageType = std::conditional_t<std::is_reference_v<T>,
                                                   std::remove_reference_t<T> *,
                                                   T>;

        public:
            constexpr Option() noexcept
                : m_has_value(false)
            {
            }

            constexpr Option(NoneType) noexcept
                : m_has_value(false)
            {
            }

            explicit constexpr Option(T t_value)
                : m_has_value(true)
            {
                if constexpr (std::is_reference_v<T>)
                {
                    new (&m_storage) StorageType(&t_value);
                }
                else
                {
                    new (&m_storage) T(std::move(t_value));
                }
            }

            ~Option()
            {
                if (m_has_value)
                {
                    reinterpret_cast<StorageType *>(&m_storage)->~StorageType();
                }
            }

        public:
            bool operator==(const Option<T> &other) const
            {
                bool both_none = is_none() && other.is_none();
                bool both_some = is_some() && other.is_some();
                return both_none || (both_some && (value() == other.value()));
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
            T unwrap() const
            {
                assert(is_some() && "called `Option::unwrap()` on a `None` value");
                return value();
            }

            T unwrap_or(T value_when_none) const
            {
                if (is_some())
                {
                    return value();
                }
                return value_when_none;
            }

            /// Returns true if the option is a `Some` value.
            ///
            /// # Examples
            /// ```cpp
            /// Option<int> x = Some(5);
            /// assert(x.is_some() == true);
            /// ```
            ///
            /// ```cpp
            /// Option<int> x = None;
            /// assert(x.is_some() == false);
            /// ```
            /// @return
            bool is_some() const
            {
                return m_has_value;
            }

            /// Returns true if the option is a `None` value.
            ///
            /// # Examples
            /// ```cpp
            /// Option<int> x = Some(5);
            /// assert(x.is_none() == false);
            /// ```
            ///
            /// ```cpp
            /// Option<int> x = None;
            /// assert(x.is_none() == true);
            /// ```
            /// @return
            bool is_none() const
            {
                return !is_some();
            }

        private:
            T value() const
            {
                if constexpr (std::is_reference_v<T>)
                {
                    return **reinterpret_cast<const StorageType *>(&m_storage);
                }
                else
                {
                    return *reinterpret_cast<const T *>(&m_storage);
                }
            }

            T value()
            {
                if constexpr (std::is_reference_v<T>)
                {
                    return **reinterpret_cast<StorageType *>(&m_storage);
                }
                else
                {
                    return *reinterpret_cast<T *>(&m_storage);
                }
            }

        private:
            bool m_has_value;
            std::aligned_storage_t<sizeof(StorageType), alignof(StorageType)> m_storage;
        };

        // For lvalue references - preserve the reference
        template <typename T>
        Option<T &> Some(T &value)
        {
            return Option<T &>(value);
        }

        template <typename T>
        Option<std::decay_t<T>> Some(const T &value)
        {
            return Option<std::decay_t<T>>(value);
        }

        // For rvalues - take by value
        template <typename T>
        Option<std::decay_t<T>> Some(T &&value)
        {
            return Option<std::decay_t<T>>(std::forward<T>(value));
        }
    } // namespace option
} // namespace carrots_std

#endif