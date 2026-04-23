#pragma once

#include "tmx/internal/type_quat.hpp"

namespace tmx
{
    namespace Quaternion
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> lerpUnclamped(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> lerp(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> slerpUnclamped(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> slerp(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;

    } // namespace Vector
    
} // namespace tmx

#include "tmx/internal/quat/compute_interpolation.inl"
