#pragma once
#include "setup.hpp"

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
            T data[2];
        };

        TMX_INLINE constexpr vec(T x, T y) noexcept;
        TMX_INLINE constexpr vec(T scalar = static_cast<T>(0.0)) noexcept; 
        TMX_INLINE constexpr vec(const vec<2, T>& v) noexcept;


        TMX_INLINE constexpr vec<2, T>& operator=(const vec<2, T>& v) = default;


        TMX_INLINE constexpr vec<2, T>& operator+=(const vec<2, T>& v);
        TMX_INLINE constexpr vec<2, T>& operator+=(T scalar);

        TMX_INLINE constexpr vec<2, T>& operator-=(const vec<2, T>& v);
        TMX_INLINE constexpr vec<2, T>& operator-=(T scalar);

        TMX_INLINE constexpr vec<2, T>& operator*=(const vec<2, T>& v);
        TMX_INLINE constexpr vec<2, T>& operator*=(T scalar);

        TMX_INLINE constexpr vec<2, T>& operator/=(const vec<2, T>& v);
        TMX_INLINE constexpr vec<2, T>& operator/=(T scalar);



        TMX_INLINE constexpr vec<2, T> operator+(const vec<2, T>& v) const;
        TMX_INLINE constexpr vec<2, T> operator+(T scalar) const;
        
    };
}

#include "type_vec2.inl"