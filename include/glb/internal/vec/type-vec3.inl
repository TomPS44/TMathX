
#include "glb/internal/compute/compute-vec.h"

namespace glb
{
    template<typename T>
    GLB_INLINE constexpr vec<3, T>::vec(T vx, T vy, T vz) noexcept
    : x(vx), y(vy), z(vz)
    {}

    template<typename T>
    GLB_INLINE constexpr vec<3, T>::vec(T scalar) noexcept
    : x(scalar), y(scalar), z(scalar)
    {}

    template<typename T>
    GLB_INLINE constexpr vec<3, T>::vec(const vec<2, T>& xy, T vz) noexcept
    : x(xy.x), y(xy.y), z(vz)
    {}

    template<typename T>
    GLB_INLINE constexpr vec<3, T>::vec(const vec<3, T>& v) noexcept
    : x(v.x), y(v.y), z(v.z)
    {}
    template<typename T>
    GLB_INLINE constexpr vec<3, T>::vec(const vec<4, T>& v) noexcept
    : x(v.x), y(v.y), z(v.z)
    {}



    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator=(T scalar) noexcept
    {
        *this = vec<3, T>(scalar);
        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr T& vec<3, T>::operator[](int i)
    {
        return values[i];
    }
    template<typename T>
    GLB_INLINE constexpr const T& vec<3, T>::operator[](int i) const
    {
        return values[i];
    }


    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator+=(const vec<3, T>& v) noexcept
    {
        *this = *this + v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator+=(T scalar) noexcept
    {
        *this = *this + vec<3, T>(scalar);

        return *this;
    }



    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator-=(const vec<3, T>& v) noexcept
    {
        *this = *this - v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator-=(T scalar) noexcept
    {
        *this = *this - vec<3, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator*=(const vec<3, T>& v) noexcept
    {
        *this = *this * v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator*=(T scalar) noexcept
    {
        *this = *this * vec<3, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator/=(const vec<3, T>& v) noexcept
    {
        *this = *this / v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator/=(T scalar) noexcept
    {
        *this = *this / vec<3, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator%=(const vec<3, T>& v) noexcept
    {
        *this = *this % v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator%=(T scalar) noexcept
    {
        *this = *this % vec<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator&=(const vec<3, T>& v) noexcept
    {
        *this = *this & v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator&=(T scalar) noexcept
    {
        *this = *this & vec<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator|=(const vec<3, T>& v) noexcept
    {
        *this = *this | v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator|=(T scalar) noexcept
    {
        *this = *this | vec<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator^=(const vec<3, T>& v) noexcept
    {
        *this = *this ^ v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator^=(T scalar) noexcept
    {
        *this = *this ^ vec<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator<<=(const vec<3, T>& v) noexcept
    {
        *this = *this << v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator<<=(T scalar) noexcept
    {
        *this = *this << vec<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator>>=(const vec<3, T>& v) noexcept
    {
        *this = *this >> v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T>& vec<3, T>::operator>>=(T scalar) noexcept
    {
        *this = *this >> vec<3, T>(scalar);

        return *this;
    }
}