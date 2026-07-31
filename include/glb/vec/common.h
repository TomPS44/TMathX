#pragma once

#include "../internal/type-vec.h"

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Min(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Min(const vec<S, T>& v, T scalar) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Max(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Max(const vec<S, T>& v, T scalar) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Abs(const vec<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Clamp(const vec<S, T>& v, const vec<S, T>& minVal, const vec<S, T>& mxVal) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Clamp(const vec<S, T>& v, T minVal, T mxVal) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Clamp01(const vec<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Saturate(const vec<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Floor(const vec<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Ceil(const vec<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Round(const vec<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Trunc(const vec<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Mod(const vec<S, T>& v, const vec<S, T>& modulus) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Mod(const vec<S, T>& v, T modulus) noexcept;
    }
}

#include "../internal/vec/compute-common.inl"