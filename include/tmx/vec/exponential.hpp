#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vector
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> pow(const vec<S, T>& v, const vec<S, T>& exponent) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> pow(const vec<S, T>& v, T exponent) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> sqrt(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> invSqrt(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> exp(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> exp2(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> log(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> log2(const vec<S, T>& v) noexcept;
    }
}

#include "tmx/internal/vec/compute_exponential.inl"