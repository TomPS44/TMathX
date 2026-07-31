#pragma once
#include "../definitions.h"
#include "../type-vec.h"

namespace glb
{
    template<typename T>
    struct GLB_ALIGN_(T) vec<3, T>
    {
        union 
        {
            struct { T x, y, z; };
            struct { T r, g, b; };
            struct { T s, t, p; };
            T values[3];
        };

        GLB_INLINE explicit constexpr vec(T x, T y, T z = static_cast<T>(0.0)) noexcept;
        GLB_INLINE explicit constexpr vec(T scalar = static_cast<T>(0.0)) noexcept; 
        GLB_INLINE explicit constexpr vec(const vec<2, T>& xy, T vz = static_cast<T>(0.0)) noexcept;
        GLB_INLINE constexpr vec(const vec<3, T>& v) noexcept;
        GLB_INLINE explicit constexpr vec(const vec<4, T>& v) noexcept;


        GLB_INLINE constexpr const T* data() const noexcept { return &x; };


        GLB_INLINE constexpr T& operator[](int index);
        GLB_INLINE constexpr const T& operator[](int index) const;

        GLB_INLINE constexpr explicit operator vec<2, T>() const noexcept { return vec<2, T>(*this); };
        GLB_INLINE constexpr explicit operator vec<4, T>() const noexcept { return vec<4, T>(*this); };

        GLB_INLINE constexpr vec<3, T>& operator=(const vec<3, T>& v) noexcept = default;
        GLB_INLINE constexpr vec<3, T>& operator=(T scalar) noexcept;


        GLB_INLINE constexpr vec<3, T>& operator+=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator+=(T scalar) noexcept;

        GLB_INLINE constexpr vec<3, T>& operator-=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator-=(T scalar) noexcept;

        GLB_INLINE constexpr vec<3, T>& operator*=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr vec<3, T>& operator/=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator/=(T scalar) noexcept;

        GLB_INLINE constexpr vec<3, T>& operator%=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator%=(T scalar) noexcept;

        GLB_INLINE constexpr vec<3, T>& operator&=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator&=(T scalar) noexcept;

        GLB_INLINE constexpr vec<3, T>& operator|=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator|=(T scalar) noexcept;

        GLB_INLINE constexpr vec<3, T>& operator^=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator^=(T scalar) noexcept;

        GLB_INLINE constexpr vec<3, T>& operator<<=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator<<=(T scalar) noexcept;

        GLB_INLINE constexpr vec<3, T>& operator>>=(const vec<3, T>& v) noexcept;
        GLB_INLINE constexpr vec<3, T>& operator>>=(T scalar) noexcept;
    };   
}

#include "type-vec3.inl"