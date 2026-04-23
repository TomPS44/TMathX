#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vector
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> greaterThan(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> greaterThanOrEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> lessThan(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> lessThanOrEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> equal(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> notEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> equal(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> notEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S>
        TMX_INLINE constexpr bool any(const vec<S, bool>& v) noexcept;
        template<size_t S>
        TMX_INLINE constexpr bool all(const vec<S, bool>& v) noexcept;

    } // namespace Vector
} // namespace tmx

#include "tmx/internal/vec/compute_relational.inl"