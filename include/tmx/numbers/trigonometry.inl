
#include <cmath>
#include <limits>

#include "tmx/internal/setup.hpp"

namespace tmx
{
    template<typename T>
    TMX_INLINE constexpr T toRadians(T ang) noexcept
    {
        return ang * tmx::degToRad<T>();
    }
    template<typename T>
    TMX_INLINE constexpr T toDegrees(T ang) noexcept
    {
        return ang * tmx::radToDeg<T>();
    }


    template<typename T>
    TMX_INLINE constexpr T cos(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::cos(ang);
    }
    template<typename T>
    TMX_INLINE constexpr T sin(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::sin(ang);
    }
    template<typename T>
    TMX_INLINE constexpr T tan(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::tan(ang);
    }


    template<typename T>
    TMX_INLINE constexpr T cosh(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::cosh(ang);
    }
    template<typename T>
    TMX_INLINE constexpr T sinh(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::sinh(ang);
    }
    template<typename T>
    TMX_INLINE constexpr T tanh(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::tanh(ang);
    }

    
    template<typename T>
    TMX_INLINE constexpr T acos(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::acos(ang);
    }
    template<typename T>
    TMX_INLINE constexpr T asin(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::asin(ang);
    }
    template<typename T>
    TMX_INLINE constexpr T atan(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::atan(ang);
    }
    template<typename T>
    TMX_INLINE constexpr T atan2(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::atan2(ang);
    }


    template<typename T>
    TMX_INLINE constexpr T acosh(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::acosh(ang);
    }
    template<typename T>
    TMX_INLINE constexpr T asinh(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::asinh(ang);
    }
    template<typename T>
    TMX_INLINE constexpr T atanh(T ang) noexcept
    {
        static_assert(std::numeric_limits<T>::is_iec559, "Cos only accepts float, double, and long double type !");
        return std::atanh(ang);
    }
}