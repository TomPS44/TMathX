#pragma once

#include "tmx/internal/definitions.hpp"
#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    template<typename T>
    struct vec<2, T>
    {
        union 
        {
            struct { T x, y; };
            struct { T r, g; };
            struct { T s, t; };
            T values[2];
        };

        TMX_INLINE constexpr vec(T x, T y) noexcept;
        TMX_INLINE constexpr vec(T scalar = static_cast<T>(0.0)) noexcept; 
        TMX_INLINE constexpr vec(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec(const vec<3, T>& v) noexcept;
        TMX_INLINE constexpr vec(const vec<4, T>& v) noexcept;


        TMX_INLINE constexpr T& operator[](size_t index);
        TMX_INLINE constexpr const T& operator[](size_t index) const;


        TMX_INLINE constexpr operator vec<3, T>() const noexcept { return vec<3, T>(*this); };
        TMX_INLINE constexpr operator vec<4, T>() const noexcept { return vec<4, T>(*this); };


        TMX_INLINE constexpr vec<2, T>& operator=(const vec<2, T>& v) noexcept = default;
        TMX_INLINE constexpr vec<2, T>& operator=(T scalar) noexcept;


        TMX_INLINE constexpr vec<2, T>& operator+=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator+=(T scalar) noexcept;

        TMX_INLINE constexpr vec<2, T>& operator-=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator-=(T scalar) noexcept;

        TMX_INLINE constexpr vec<2, T>& operator*=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator*=(T scalar) noexcept;

        TMX_INLINE constexpr vec<2, T>& operator/=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator/=(T scalar) noexcept;

        TMX_INLINE constexpr vec<2, T>& operator%=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator%=(T scalar) noexcept;


        TMX_INLINE constexpr vec<2, T>& operator&=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator&=(T scalar) noexcept;

        TMX_INLINE constexpr vec<2, T>& operator|=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator|=(T scalar) noexcept;

        TMX_INLINE constexpr vec<2, T>& operator^=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator^=(T scalar) noexcept;

        TMX_INLINE constexpr vec<2, T>& operator<<=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator<<=(T scalar) noexcept;

        TMX_INLINE constexpr vec<2, T>& operator>>=(const vec<2, T>& v) noexcept;
        TMX_INLINE constexpr vec<2, T>& operator>>=(T scalar) noexcept;
    };
}

#include "type_vec2.inl"