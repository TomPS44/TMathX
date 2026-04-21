#pragma once

#include <tmx/internal/setup.hpp>

namespace tmx
{
    template<typename T>
    TMX_INLINE constexpr T zero() noexcept;
    template<typename T>
    TMX_INLINE constexpr T one() noexcept;
    template<typename T>
    TMX_INLINE constexpr T espilon() noexcept;
    template<typename T>
    TMX_INLINE constexpr T e() noexcept;
    template<typename T>
    TMX_INLINE constexpr T pi() noexcept;
    template<typename T>
    TMX_INLINE constexpr T halfPi() noexcept;
    template<typename T>
    TMX_INLINE constexpr T twoPi() noexcept;
    template<typename T>
    TMX_INLINE constexpr T quarterPi() noexcept;
    template<typename T>
    TMX_INLINE constexpr T invPi() noexcept;
    template<typename T>
    TMX_INLINE constexpr T invSqrtPi() noexcept;
    template<typename T>
    TMX_INLINE constexpr T twoOverPi() noexcept;
    template<typename T>
    TMX_INLINE constexpr T phi() noexcept;
    template<typename T>
    TMX_INLINE constexpr T sqrt2() noexcept;
    template<typename T>
    TMX_INLINE constexpr T sqrt3() noexcept;
    template<typename T>
    TMX_INLINE constexpr T ln2() noexcept;
    template<typename T>
    TMX_INLINE constexpr T ln10() noexcept;
    template<typename T>
    TMX_INLINE constexpr T invSqrt3() noexcept;
    template<typename T>
    TMX_INLINE constexpr T euler() noexcept;

    template<typename T>
    TMX_INLINE constexpr T degToRad() noexcept;
    template<typename T>
    TMX_INLINE constexpr T radToDeg() noexcept;
}

#include "tmx/numbers/constants.inl"