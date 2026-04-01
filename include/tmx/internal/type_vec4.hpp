#pragma once
#include "setup.hpp"

namespace tmx
{
    template<typename T>
    struct vec<4, T>
    {
        union 
        {
            struct { T x, y, z, w; };
            struct { T r, g, b, a; };
            struct { T s, t, p, q; };
            T data[4];
        };

        TMX_INLINE constexpr vec(T vx, T vy, T vz, T vw) noexcept;
        TMX_INLINE constexpr vec(T scalar = static_cast<T>(0.0)) noexcept; 
        TMX_INLINE constexpr vec(const vec<4, T>& v) noexcept;


        TMX_INLINE constexpr vec<4, T>& operator=(const vec<4, T>& v) = default;


        TMX_INLINE constexpr vec<4, T>& operator+=(const vec<4, T>& v);
        TMX_INLINE constexpr vec<4, T>& operator+=(T scalar);

        TMX_INLINE constexpr vec<4, T>& operator-=(const vec<4, T>& v);
        TMX_INLINE constexpr vec<4, T>& operator-=(T scalar);

        TMX_INLINE constexpr vec<4, T>& operator*=(const vec<4, T>& v);
        TMX_INLINE constexpr vec<4, T>& operator*=(T scalar);

        TMX_INLINE constexpr vec<4, T>& operator/=(const vec<4, T>& v);
        TMX_INLINE constexpr vec<4, T>& operator/=(T scalar);



        TMX_INLINE constexpr vec<4, T> operator+(const vec<4, T>& v) const;
        TMX_INLINE constexpr vec<4, T> operator+(T scalar) const;
        
    };
}

#include "type_vec2.inl"