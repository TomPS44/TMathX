
#include "compute/compute-mat.h"
#include <limits>

namespace glb
{
    // --- Unary operators ---

    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& m) noexcept
    {
        return m;
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& m) noexcept
    {
        return glbInternal::matNeg<R, C, T, glbInternal::useSimd<R, T>::value>::call(m);
    }



    // --- Arithmetic operators

    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return glbInternal::matAdd<R, C, T, glbInternal::useSimd<R, T>::value>::call(a, b);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& m, T scalar) noexcept
    {
        return glbInternal::matAdd<R, C, T, glbInternal::useSimd<R, T>::value>::call(m, scalar);
    }
    


    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return glbInternal::matSub<R, C, T, glbInternal::useSimd<R, T>::value>::call(a, b);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& m, T scalar) noexcept
    {
        return glbInternal::matSub<R, C, T, glbInternal::useSimd<R, T>::value>::call(m, scalar);
    }


    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator*(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return glbInternal::matMul<R, C, T, glbInternal::useSimd<R, T>::value>::call(a, b);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator*(const mat<R, C, T>& m, T scalar) noexcept
    {
        return glbInternal::matMul<R, C, T, glbInternal::useSimd<R, T>::value>::call(m, scalar);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator*(T scalar, const mat<R, C, T>& m) noexcept
    {
        return glbInternal::matMul<R, C, T, glbInternal::useSimd<R, T>::value>::call(m, scalar);
    }

    template<int R, int C, typename T>
    GLB_INLINE constexpr typename mat<R, C, T>::colType operator*(const mat<R, C, T>& m, const typename mat<R, C, T>::colType& v) noexcept
    {
        return glbInternal::matMul<R, C, T, glbInternal::useSimd<R, T>::value>::call(m, v);
    }


    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator/(const mat<R, C, T>& m, T scalar) noexcept
    {
        return glbInternal::matDiv<R, C, T, glbInternal::useSimd<R, T>::value>::call(m, scalar);
    }




    template<int R, int C, typename T>
    GLB_INLINE constexpr bool operator==(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return glbInternal::matEqual<R, C, T>::call(a, b);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr bool operator!=(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return !(a == b);
    }
}