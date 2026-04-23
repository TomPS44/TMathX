#include <limits>
#include "tmx/internal/compute/compute_quat.hpp"

namespace tmx
{
    // --- Constructors ---

    template<typename T>
    TMX_INLINE constexpr quat<T>::quat(T qw, T qx, T qy, T qz) noexcept
    : w(qw), x(qx), y(qy), z(qz)
    {}

    template<typename T>
    TMX_INLINE constexpr quat<T>::quat(T qw, const vec<3, T>& xyz) noexcept
    : w(qw), x(xyz.x), y(xyz.y), z(xyz.z)
    {}

    template<typename T>
    TMX_INLINE constexpr quat<T>::quat(const quat<T>& q) noexcept
    : w(q.w), x(q.x), y(q.y), z(q.z)
    {}

    template<typename T>
    TMX_INLINE constexpr quat<T>::quat() noexcept
    : w(1), x(0), y(0), z(0)
    {}

    // --- Accessors ---

    template<typename T>
    TMX_INLINE constexpr T& quat<T>::operator[](size_t i) 
    {
        return values[i];
    }
    template<typename T>
    TMX_INLINE constexpr const T quat<T>::operator[](size_t i) const
    {
        return values[i];
    }

    // --- Reference operators ---

    template<typename T>
    TMX_INLINE constexpr quat<T>& quat<T>::operator+=(const quat<T>& q) noexcept
    {
        *this = *this + q;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr quat<T>& quat<T>::operator-=(const quat<T>& q) noexcept
    {
        *this = *this - q;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr quat<T>& quat<T>::operator*=(const quat<T>& q) noexcept
    {
        *this = *this * q;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr quat<T>& quat<T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }

    template<typename T>
    TMX_INLINE constexpr quat<T>& quat<T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }

    // --- Unary operators ---

    template<typename T>
    TMX_INLINE constexpr quat<T> operator+(const quat<T>& q) noexcept
    {
        return q;
    }
    template<typename T>
    TMX_INLINE constexpr quat<T> operator-(const quat<T>& q) noexcept
    {
        return quat<T>(-q.w, -q.x, -q.y, -q.z);
    }


    // --- Operators ---

    template<typename T>
    TMX_INLINE constexpr quat<T> operator+(const quat<T>& a, const quat<T>& b) noexcept
    {
        return internal::quatAdd<T, internal::useSimd<4, T>::value>::call(a, b);
    }
    template<typename T>
    TMX_INLINE constexpr quat<T> operator-(const quat<T>& a, const quat<T>& b) noexcept
    {
        return internal::quatSub<T, internal::useSimd<4, T>::value>::call(a, b);
    }

    template<typename T>
    TMX_INLINE constexpr quat<T> operator*(const quat<T>& a, const quat<T>& b) noexcept
    {
        
        return internal::quatMul<T, internal::useSimd<4, T>::value>::call(a, b);
    }
    template<typename T>
    TMX_INLINE constexpr quat<T> operator*(const quat<T>& q, T scalar) noexcept
    {
        return internal::quatMul<T, internal::useSimd<4, T>::value>::call(q, scalar);
    }
    template<typename T>
    TMX_INLINE constexpr quat<T> operator*(T scalar, const quat<T>& q) noexcept
    {
        return internal::quatMul<T, internal::useSimd<4, T>::value>::call(q, scalar);
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(const quat<T>& rot, const vec<3, T>& point) noexcept
    {
        // TODO

        // quat normQ = normalized(rot)
        // vec3 u = (normQ.x, normQ.y, normQ.z)
        //
        // vec3 t = cross(u, point) * 2
        //
        // vec3 final = point + (t * normQ.w) + cross(u, t)
    }


    template<typename T>
    TMX_INLINE constexpr quat<T> operator/(const quat<T>& q, T scalar) noexcept
    {
        return internal::quatDiv<T, internal::useSimd<4, T>::value>::call(q, scalar);
    }
    template<typename T>
    TMX_INLINE constexpr quat<T> operator/(T scalar, const quat<T>& q) noexcept
    {
        return internal::quatDiv<T, internal::useSimd<4, T>::value>::call(scalar, q);
    }



    template<typename T>
    TMX_INLINE constexpr bool operator==(const quat<T>& a, const quat<T>& b) noexcept
    {
        return 
            internal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.x, b.x) &&
            internal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.y, b.y) &&
            internal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.z, b.z) &&
            internal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.w, b.w);
    }
    template<typename T>
    TMX_INLINE constexpr bool operator!=(const quat<T>& a, const quat<T>& b) noexcept
    {
        return !(a == b); 
    }


}