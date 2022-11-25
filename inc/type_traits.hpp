#ifndef FT_TYPE_TRAITS_HPP
#define FT_TYPE_TRAITS_HPP

namespace ft
{

    /**
     * @brief If B is true, std::enable_if has a public member typedef type, equal
     * to T; otherwise, there is no member typedef.
     */
    template <bool B, class T = void>
    struct enable_if
    {
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    struct true_type
    {
        static const bool value = true;
        typedef bool value_type;
        typedef true_type type;
    };

    struct false_type
    {
        static const bool value = false;
        typedef bool value_type;
        typedef false_type type;
    };

    /**
     * @brief Checks whether T is an integral type. Provides the member
     * constant value which is equal to true, if T is the type bool, char, char8_t
     * (since C++20), char16_t, char32_t, wchar_t, short, int, long, long long, or
     * any implementation-defined extended integer types, including any signed,
     * unsigned, and cv-qualified variants. Otherwise, value is equal to false.
     *
     * @tparam T integral type
     */
    template <class T>
    struct is_integral : public false_type
    {
    };

    template <>
    struct is_integral<bool> : public true_type
    {
    };
    template <>
    struct is_integral<char> : public true_type
    {
    };
    template <>
    struct is_integral<char16_t> : public true_type
    {
    };
    template <>
    struct is_integral<char32_t> : public true_type
    {
    };
    template <>
    struct is_integral<wchar_t> : public true_type
    {
    };
    template <>
    struct is_integral<signed char> : public true_type
    {
    };
    template <>
    struct is_integral<short int> : public true_type
    {
    };
    template <>
    struct is_integral<int> : public true_type
    {
    };
    template <>
    struct is_integral<long int> : public true_type
    {
    };
    template <>
    struct is_integral<long long int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned char> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned short int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned long int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned long long int> : public true_type
    {
    };

} // namespace ft

#endif // FT__TYPE_TRAITS_HPP