#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vector
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> min(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> min(const vec<S, T>& v, T scalar) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> max(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> max(const vec<S, T>& v, T scalar) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> abs(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> clamp(const vec<S, T>& v, const vec<S, T>& minVal, const vec<S, T>& mxVal) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> clamp(const vec<S, T>& v, T minVal, T mxVal) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> floor(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> ceil(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> round(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> trunc(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> mod(const vec<S, T>& v, const vec<S, T>& modulus) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> mod(const vec<S, T>& v, T modulus) noexcept;
    }
}

#include "tmx/internal/vec/compute_common.inl"