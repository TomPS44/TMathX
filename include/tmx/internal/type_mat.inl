
#include "tmx/internal/compute/compute_mat.hpp"
#include <limits>

namespace tmx
{
    // --- Unary operators ---

    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& m) noexcept
    {
        return m;
    }
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& m) noexcept
    {
        return internal::matNeg<R, C, T, internal::useSimd<R, T>::value>::call(m);
    }



    // --- Arithmetic operators

    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return internal::matAdd<R, C, T, internal::useSimd<R, T>::value>::call(a, b);
    }
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& m, T scalar) noexcept
    {
        return internal::matAdd<R, C, T, internal::useSimd<R, T>::value>::call(m, scalar);
    }
    


    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return internal::matSub<R, C, T, internal::useSimd<R, T>::value>::call(a, b);
    }
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& m, T scalar) noexcept
    {
        return internal::matSub<R, C, T, internal::useSimd<R, T>::value>::call(m, scalar);
    }


    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator*(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return internal::matMul<R, C, T, internal::useSimd<R, T>::value>::call(a, b);
    }
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator*(const mat<R, C, T>& m, T scalar) noexcept
    {
        return internal::matMul<R, C, T, internal::useSimd<R, T>::value>::call(m, scalar);
    }
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator*(T scalar, const mat<R, C, T>& m) noexcept
    {
        return internal::matMul<R, C, T, internal::useSimd<R, T>::value>::call(m, scalar);
    }

    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr typename mat<R, C, T>::colType operator*(const mat<R, C, T>& m, const typename mat<R, C, T>::colType& v) noexcept
    {
        return internal::matMul<R, C, T, internal::useSimd<R, T>::value>::call(m, v);
    }


    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator/(const mat<R, C, T>& m, T scalar) noexcept
    {
        return internal::matDiv<R, C, T, internal::useSimd<R, T>::value>::call(m, scalar);
    }




    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr bool operator==(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return internal::matEqual<R, C, T>::call(a, b);
    }
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr bool operator!=(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept
    {
        return !(a == b);
    }
}