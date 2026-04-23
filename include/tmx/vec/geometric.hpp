#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vector
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr T dot(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr T length(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr T lengthSquared(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr T distance(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr T distanceSquared(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> cross(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> normalize(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> faceForward(const vec<S, T>& N, const vec<S, T>& I, const vec<S, T>& Nref) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> reflect(const vec<S, T>& I, const vec<S, T>& N) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> refract(const vec<S, T>& I, const vec<S, T>& N, T eta) noexcept;
    } // namespace Vector
}

#include "tmx/internal/vec/compute_geometric.inl"