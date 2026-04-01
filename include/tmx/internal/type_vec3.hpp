#pragma once
#include "tmx/internal/definitions.hpp"

namespace tmx
{
    template<typename T>
    struct vec<3, T>
    {
        union 
        {
            struct { T x, y, z; };
            struct { T r, g, b; };
            struct { T s, t, p; };
            T data[3];
        };

        TMX_INLINE constexpr vec(T x, T y, T z = static_cast<T>(0.0)) noexcept;
        TMX_INLINE constexpr vec(T scalar = static_cast<T>(0.0)) noexcept; 
        TMX_INLINE constexpr vec(const vec<3, T>& v) noexcept;


        TMX_INLINE constexpr vec<3, T>& operator=(const vec<3, T>& v) = default;


        TMX_INLINE constexpr vec<3, T>& operator+=(const vec<3, T>& v);
        TMX_INLINE constexpr vec<3, T>& operator+=(T scalar);

        TMX_INLINE constexpr vec<3, T>& operator-=(const vec<3, T>& v);
        TMX_INLINE constexpr vec<3, T>& operator-=(T scalar);

        TMX_INLINE constexpr vec<3, T>& operator*=(const vec<3, T>& v);
        TMX_INLINE constexpr vec<3, T>& operator*=(T scalar);

        TMX_INLINE constexpr vec<3, T>& operator/=(const vec<3, T>& v);
        TMX_INLINE constexpr vec<3, T>& operator/=(T scalar);

        TMX_INLINE constexpr vec<3, T>& operator%=(const vec<3, T>& v);
        TMX_INLINE constexpr vec<3, T>& operator%=(T scalar);
    };



    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator+(const vec<3, T>& v) noexcept; 
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator-(const vec<3, T>& v) noexcept; 


    
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator+(const vec<3, T>& a, const vec<3, T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator+(const vec<3, T>& v, T scalar) noexcept;

    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator-(const vec<3, T>& a, const vec<3, T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator-(const vec<3, T>& v, T scalar) noexcept;

    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(const vec<3, T>& a, const vec<3, T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(const vec<3, T>& v, T scalar) noexcept;
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(T scalar, const vec<3, T>& v) noexcept;

    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator/(const vec<3, T>& a, const vec<3, T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator/(const vec<3, T>& v, T scalar) noexcept;

    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator%(const vec<3, T>& a, const vec<3, T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator%(const vec<3, T>& v, T scalar) noexcept;
    
}

#include "type_vec3.inl"