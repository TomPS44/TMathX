#pragma once

#include "tmx/internal/setup.hpp"

namespace tmx
{
    template<typename T>
    TMX_INLINE constexpr T toRadians(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T toDegrees(T ang) noexcept;

    template<typename T>
    TMX_INLINE constexpr T cos(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T sin(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T tan(T ang) noexcept;
    
    template<typename T>
    TMX_INLINE constexpr T cosh(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T sinh(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T tanh(T ang) noexcept;

    template<typename T>
    TMX_INLINE constexpr T acos(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T asin(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T atan(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T atan2(T ang) noexcept;

    template<typename T>
    TMX_INLINE constexpr T acosh(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T asinh(T ang) noexcept;
    template<typename T>
    TMX_INLINE constexpr T atanh(T ang) noexcept;
} // namespace tmx

#include "tmx/numbers/trigonometry.inl"
