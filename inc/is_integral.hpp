#ifndef FT_IS_INTEGRAL_HPP
#define FT_IS_INTEGRAL_HPP

/**
 * * is_integral
 * Trait class that identifies whether T is an integral type.
 * fundamental inergral types list:
 * https://cplusplus.com/reference/type_traits/is_integral/
 */
template <bool is_integral, typename T>
struct is_integral_res
{
    typedef T type;
    static const bool value = is_integral;
};
    template <typename>
        struct is_integral_type : public is_integral_res<false, bool> {};

    template <>
        struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    template <>
        struct is_integral_type<char> : public is_integral_res<true, char> {};

    template <>
        struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    template <>
        struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    template <>
        struct is_integral_type<int> : public is_integral_res<true, int> {};

    template <>
        struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    template <>
        struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    template <>
        struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    template <>
        struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    template <>
        struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    template <>
        struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

    template <typename T>
        struct is_integral : public is_integral_type<T> { };

#endif