#pragma once

#include "../internal/type-vec.h"

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Pow(const vec<S, T>& v, const vec<S, T>& exponent) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Pow(const vec<S, T>& v, T exponent) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Sqrt(const vec<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> InvSqrt(const vec<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Exp(const vec<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Exp2(const vec<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Log(const vec<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Log2(const vec<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Log10(const vec<S, T>& v) noexcept;
    }
}

#include "../internal/vec/compute-exponential.inl"