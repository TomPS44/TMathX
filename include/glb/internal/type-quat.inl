#include <limits>
#include "compute/compute-quat.h"

namespace glb
{
    // --- Constructors ---

    template<typename T>
    GLB_INLINE constexpr quat<T>::quat(T qw, T qx, T qy, T qz) noexcept
    : w(qw), x(qx), y(qy), z(qz)
    {}

    template<typename T>
    GLB_INLINE constexpr quat<T>::quat(T qw, const vec<3, T>& xyz) noexcept
    : w(qw), x(xyz.x), y(xyz.y), z(xyz.z)
    {}

    template<typename T>
    GLB_INLINE constexpr quat<T>::quat(const quat<T>& q) noexcept
    : w(q.w), x(q.x), y(q.y), z(q.z)
    {}

    template<typename T>
    GLB_INLINE constexpr quat<T>::quat() noexcept
    : w(static_cast<T>(1)), x(static_cast<T>(0)), y(static_cast<T>(0)), z(static_cast<T>(0))
    {}

    // --- Accessors ---

    template<typename T>
    GLB_INLINE constexpr T& quat<T>::operator[](int i) 
    {
        return (&w)[i];
    }
    template<typename T>
    GLB_INLINE constexpr const T quat<T>::operator[](int i) const
    {
        return (&w)[i];
    }

    // --- Reference operators ---

    template<typename T>
    GLB_INLINE constexpr quat<T>& quat<T>::operator+=(const quat<T>& q) noexcept
    {
        *this = *this + q;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr quat<T>& quat<T>::operator-=(const quat<T>& q) noexcept
    {
        *this = *this - q;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr quat<T>& quat<T>::operator*=(const quat<T>& q) noexcept
    {
        *this = *this * q;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr quat<T>& quat<T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr quat<T>& quat<T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }

    // --- Unary operators ---

    template<typename T>
    GLB_INLINE constexpr quat<T> operator+(const quat<T>& q) noexcept
    {
        return q;
    }
    template<typename T>
    GLB_INLINE constexpr quat<T> operator-(const quat<T>& q) noexcept
    {
        return quat<T>(-q.w, -q.x, -q.y, -q.z);
    }


    // --- Operators ---

    template<typename T>
    GLB_INLINE constexpr quat<T> operator+(const quat<T>& a, const quat<T>& b) noexcept
    {
        return glbInternal::quatAdd<T, glbInternal::useSimd<4, T>::value>::call(a, b);
    }
    template<typename T>
    GLB_INLINE constexpr quat<T> operator-(const quat<T>& a, const quat<T>& b) noexcept
    {
        return glbInternal::quatSub<T, glbInternal::useSimd<4, T>::value>::call(a, b);
    }

    template<typename T>
    GLB_INLINE constexpr quat<T> operator*(const quat<T>& a, const quat<T>& b) noexcept
    {
        
        return glbInternal::quatMul<T, glbInternal::useSimd<4, T>::value>::call(a, b);
    }
    template<typename T>
    GLB_INLINE constexpr quat<T> operator*(const quat<T>& q, T scalar) noexcept
    {
        return glbInternal::quatMul<T, glbInternal::useSimd<4, T>::value>::call(q, scalar);
    }
    template<typename T>
    GLB_INLINE constexpr quat<T> operator*(T scalar, const quat<T>& q) noexcept
    {
        return glbInternal::quatMul<T, glbInternal::useSimd<4, T>::value>::call(q, scalar);
    }
    template<typename T>
    GLB_INLINE constexpr vec<3, T> operator*(const quat<T>& rot, const vec<3, T>& point) noexcept
    {
        const vec<3, T> u(rot.x, rot.y, rot.z);

        const vec<3, T> t = Vec::Cross(u, point) * static_cast<T>(2);


        return point + (t * rot.w) + Vec::Cross(u, t);
    }


    template<typename T>
    GLB_INLINE constexpr quat<T> operator/(const quat<T>& q, T scalar) noexcept
    {
        return glbInternal::quatDiv<T, glbInternal::useSimd<4, T>::value>::call(q, scalar);
    }
    template<typename T>
    GLB_INLINE constexpr quat<T> operator/(T scalar, const quat<T>& q) noexcept
    {
        return glbInternal::quatDiv<T, glbInternal::useSimd<4, T>::value>::call(scalar, q);
    }



    template<typename T>
    GLB_INLINE constexpr bool operator==(const quat<T>& a, const quat<T>& b) noexcept
    {
        return 
            glbInternal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.x, b.x) &&
            glbInternal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.y, b.y) &&
            glbInternal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.z, b.z) &&
            glbInternal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.w, b.w);
    }
    template<typename T>
    GLB_INLINE constexpr bool operator!=(const quat<T>& a, const quat<T>& b) noexcept
    {
        return !(a == b); 
    }


}