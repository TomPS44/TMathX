#pragma once

#include "../definitions.h"
#include "../type-vec.h"

namespace glb
{
    template<typename T>
    struct GLB_ALIGN_(T) vec<4, T>
    {
        union 
        {
            struct { T x, y, z, w; };
            struct { T r, g, b, a; };
            struct { T s, t, p, q; };
            T values[4];
            typename glbInternal::simdReg<4, T>::type reg;
        };

        GLB_INLINE explicit constexpr vec(T x, T y, T z, T w = static_cast<T>(0.0)) noexcept;
        GLB_INLINE explicit constexpr vec(T scalar = static_cast<T>(0.0)) noexcept; 
        GLB_INLINE explicit constexpr vec(const vec<3, T>& xyy, T vw = static_cast<T>(0.0)) noexcept;
        GLB_INLINE explicit constexpr vec(const vec<2, T>& v) noexcept;
        GLB_INLINE constexpr vec(const vec<4, T>& v) noexcept;


        GLB_INLINE constexpr const T* data() const noexcept { return &x; };


        GLB_INLINE constexpr T& operator[](int index);
        GLB_INLINE constexpr const T& operator[](int index) const;

        GLB_INLINE constexpr explicit operator vec<2, T>() const noexcept { return vec<2, T>(*this); };
        GLB_INLINE constexpr explicit operator vec<3, T>() const noexcept { return vec<3, T>(*this); };

        GLB_INLINE constexpr vec<4, T>& operator=(const vec<4, T>& v) noexcept = default;
        GLB_INLINE constexpr vec<4, T>& operator=(T scalar) noexcept;


        GLB_INLINE constexpr vec<4, T>& operator+=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator+=(T scalar) noexcept;

        GLB_INLINE constexpr vec<4, T>& operator-=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator-=(T scalar) noexcept;

        GLB_INLINE constexpr vec<4, T>& operator*=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr vec<4, T>& operator/=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator/=(T scalar) noexcept;

        GLB_INLINE constexpr vec<4, T>& operator%=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator%=(T scalar) noexcept;

        GLB_INLINE constexpr vec<4, T>& operator&=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator&=(T scalar) noexcept;

        GLB_INLINE constexpr vec<4, T>& operator|=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator|=(T scalar) noexcept;

        GLB_INLINE constexpr vec<4, T>& operator^=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator^=(T scalar) noexcept;

        GLB_INLINE constexpr vec<4, T>& operator<<=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator<<=(T scalar) noexcept;

        GLB_INLINE constexpr vec<4, T>& operator>>=(const vec<4, T>& v) noexcept;
        GLB_INLINE constexpr vec<4, T>& operator>>=(T scalar) noexcept;
    };
}

#include "type-vec4.inl"
