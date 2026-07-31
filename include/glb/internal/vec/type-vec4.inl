
#include "../compute/compute-vec.h"

namespace glb
{
    template<typename T>
    GLB_INLINE constexpr vec<4, T>::vec(T vx, T vy, T vz, T vw) noexcept
    : x(vx), y(vy), z(vz), w(vw)
    {}

    template<typename T>
    GLB_INLINE constexpr vec<4, T>::vec(T scalar) noexcept
    : x(scalar), y(scalar), z(scalar), w(scalar)
    {}

    template<typename T>
    GLB_INLINE constexpr vec<4, T>::vec(const vec<3, T>& xyz, T vw) noexcept
    : x(xyz.x), y(xyz.y), z(xyz.z), w(vw)
    {}

    template<typename T>
    GLB_INLINE constexpr vec<4, T>::vec(const vec<2, T>& v) noexcept
    : x(v.x), y(v.y), z(static_cast<T>(0)), w(static_cast<T>(0))
    {}
    
    template<typename T>
    GLB_INLINE constexpr vec<4, T>::vec(const vec<4, T>& v) noexcept
    : x(v.x), y(v.y), z(v.z), w(v.w)
    {}



    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator=(T scalar) noexcept
    {
        *this = vec<4, T>(scalar);
        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr T& vec<4, T>::operator[](int i)
    {
        return values[i];
    }
    template<typename T>
    GLB_INLINE constexpr const T& vec<4, T>::operator[](int i) const
    {
        return values[i];
    }


    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator+=(const vec<4, T>& v) noexcept
    {
        *this = *this + v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator+=(T scalar) noexcept
    {
        *this = *this + vec<4, T>(scalar);

        return *this;
    }



    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator-=(const vec<4, T>& v) noexcept
    {
        *this = *this - v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator-=(T scalar) noexcept
    {
        *this = *this - vec<4, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator*=(const vec<4, T>& v) noexcept
    {
        *this = *this * v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator*=(T scalar) noexcept
    {
        *this = *this * vec<4, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator/=(const vec<4, T>& v) noexcept
    {
        *this = *this / v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator/=(T scalar) noexcept
    {
        *this = *this / vec<4, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator%=(const vec<4, T>& v) noexcept
    {
        *this = *this % v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator%=(T scalar) noexcept
    {
        *this = *this % vec<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator&=(const vec<4, T>& v) noexcept
    {
        *this = *this & v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator&=(T scalar) noexcept
    {
        *this = *this & vec<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator|=(const vec<4, T>& v) noexcept
    {
        *this = *this | v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator|=(T scalar) noexcept
    {
        *this = *this | vec<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator^=(const vec<4, T>& v) noexcept
    {
        *this = *this ^ v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator^=(T scalar) noexcept
    {
        *this = *this ^ vec<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator<<=(const vec<4, T>& v) noexcept
    {
        *this = *this << v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator<<=(T scalar) noexcept
    {
        *this = *this << vec<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator>>=(const vec<4, T>& v) noexcept
    {
        *this = *this >> v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr vec<4, T>& vec<4, T>::operator>>=(T scalar) noexcept
    {
        *this = *this >> vec<4, T>(scalar);

        return *this;
    }
}

#if !defined(GLB_SIMD_NONE)
#    include "../simd/vec-compute-vec.inl"

#endif