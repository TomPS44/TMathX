
#include "tmx/internal/operations/compute_vec.hpp"

namespace tmx
{
    template<typename T>
    TMX_INLINE constexpr vec<3, T>::vec(T vx, T vy, T vz) noexcept
    : x(vx), y(vy), z(vz)
    {}

    template<typename T>
    TMX_INLINE constexpr vec<3, T>::vec(T scalar) noexcept
    : x(scalar), y(scalar), z(scalar)
    {}

    template<typename T>
    TMX_INLINE constexpr vec<3, T>::vec(const vec<3, T>& v) noexcept
    : x(v.x), y(v.y), z(v.z)
    {}




    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator+=(const vec<3, T>& v) 
    {
        *this = *this + v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator+=(T scalar) 
    {
        *this = *this + vec<3, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator+=(const vec<3, T>& v) 
    {
        *this = *this + v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator+=(T scalar) 
    {
        *this = *this + vec<3, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator-=(const vec<3, T>& v) 
    {
        *this = *this - v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator-=(T scalar) 
    {
        *this = *this - vec<3, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator*=(const vec<3, T>& v) 
    {
        *this = *this * v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator*=(T scalar) 
    {
        *this = *this * vec<3, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator/=(const vec<3, T>& v) 
    {
        *this = *this / v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator/=(T scalar) 
    {
        *this = *this / vec<3, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator%=(const vec<3, T>& v) 
    {
        *this = *this % v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T>& vec<3, T>::operator%=(T scalar) 
    {
        *this = *this % vec<3, T>(scalar);

        return *this;
    }


    

    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator+(const vec<3, T>& v) noexcept
    {
        return v;
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator-(const vec<3, T>& v) noexcept
    {
        return vec<3, T>(
            -v.x,
            -v.y,
            -v.Z
        );
    }





    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator+(const vec<3, T>& a, const vec<3, T>& b) noexcept
    {
        return internal::vecAdd<3, T, internal::useSimd<3, T>::value>::call(a, b);
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator+(const vec<3, T>& v, T scalar) noexcept
    {
        return internal::vecAdd<3, T, internal::useSimd<3, T>::value>::call(v, vec<3, T>(scalar));
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator+(T scalar, const vec<3, T>& v) noexcept
    {
        return internal::vecAdd<3, T, internal::useSimd<3, T>::value>::call(v, vec<3, T>(scalar));
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator-(const vec<3, T>& a, const vec<3, T>& b) noexcept
    {
        return internal::vecSub<3, T, internal::useSimd<3, T>::value>::call(a, b);
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator-(const vec<3, T>& v, T scalar) noexcept
    {
        return internal::vecSub<3, T, internal::useSimd<3, T>::value>::call(v, vec<3, T>(scalar));
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(const vec<3, T>& a, const vec<3, T>& b) noexcept
    {
        return internal::vecMul<3, T, internal::useSimd<3, T>::value>::call(a, b);
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(const vec<3, T>& v, T scalar) noexcept
    {
        return internal::vecMul<3, T, internal::useSimd<3, T>::value>::call(v, vec<3, T>(scalar));
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(T scalar, const vec<3, T>& v) noexcept
    {
        return internal::vecMul<3, T, internal::useSimd<3, T>::value>::call(v, vec<3, T>(scalar));
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator/(const vec<3, T>& a, const vec<3, T>& b) noexcept
    {
        return internal::vecDiv<3, T, internal::useSimd<3, T>::value>::call(a, b);
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator/(const vec<3, T>& v, T scalar) noexcept
    {
        return internal::vecDiv<3, T, internal::useSimd<3, T>::value>::call(v, vec<3, T>(scalar));
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator%(const vec<3, T>& a, const vec<3, T>& b) noexcept
    {
        return internal::vecMod<3, T, internal::useSimd<3, T>::value>::call(a, b);
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator%(const vec<3, T>& v, T scalar) noexcept
    {
        return internal::vecMod<3, T, internal::useSimd<3, T>::value>::call(v, vec<3, T>(scalar));
    }
    
}