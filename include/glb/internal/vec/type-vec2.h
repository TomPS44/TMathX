#pragma once

#include "../definitions.h"
#include "../type-vec.h"

namespace glb
{
    template<typename T>
    struct GLB_ALIGN_(T) vec<2, T>
    {
        union 
        {
            struct { T x, y; };
            struct { T r, g; };
            struct { T s, t; };
            T values[2];
        };

        GLB_INLINE explicit constexpr vec(T x, T y) noexcept;
        GLB_INLINE explicit constexpr vec(T scalar = static_cast<T>(0.0)) noexcept; 
        GLB_INLINE constexpr vec(const vec<2, T>& v) noexcept;
        GLB_INLINE explicit constexpr vec(const vec<3, T>& v) noexcept;
        GLB_INLINE explicit constexpr vec(const vec<4, T>& v) noexcept;


        GLB_INLINE constexpr const T* data() const noexcept { return &x; };


        GLB_INLINE constexpr T& operator[](int index);
        GLB_INLINE constexpr const T& operator[](int index) const;


        GLB_INLINE constexpr explicit operator vec<3, T>() const noexcept { return vec<3, T>(*this); };
        GLB_INLINE constexpr explicit operator vec<4, T>() const noexcept { return vec<4, T>(*this); };


        GLB_INLINE constexpr vec<2, T>& operator=(const vec<2, T>& v) noexcept = default;
        GLB_INLINE constexpr vec<2, T>& operator=(T scalar) noexcept;


        GLB_INLINE constexpr vec<2, T>& operator+=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator+=(T scalar) noexcept;

        GLB_INLINE constexpr vec<2, T>& operator-=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator-=(T scalar) noexcept;

        GLB_INLINE constexpr vec<2, T>& operator*=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr vec<2, T>& operator/=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator/=(T scalar) noexcept;

        GLB_INLINE constexpr vec<2, T>& operator%=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator%=(T scalar) noexcept;


        GLB_INLINE constexpr vec<2, T>& operator&=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator&=(T scalar) noexcept;

        GLB_INLINE constexpr vec<2, T>& operator|=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator|=(T scalar) noexcept;

        GLB_INLINE constexpr vec<2, T>& operator^=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator^=(T scalar) noexcept;

        GLB_INLINE constexpr vec<2, T>& operator<<=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator<<=(T scalar) noexcept;

        GLB_INLINE constexpr vec<2, T>& operator>>=(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec<2, T>& operator>>=(T scalar) noexcept;
    };
}

#include "type-vec2.inl"