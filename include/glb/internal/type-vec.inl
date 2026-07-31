
#include "compute/compute-vec.h"
#include <limits>

namespace glb
{
    // --- Unary operators ---

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator+(const vec<S, T>& v) noexcept
    {
        return v;
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator-(const vec<S, T>& v) noexcept
    {
        return glbInternal::vecNeg<S, T, glbInternal::useSimd<S, T>::value>::call(v);
    }



    // --- Arithmetic (binary) operators

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator+(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecAdd<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator+(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecAdd<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator+(T scalar, const vec<S, T>& v) noexcept
    {
        return glbInternal::vecAdd<S, T, glbInternal::useSimd<S, T>::value>::call(vec<S, T>(scalar), v);
    }


    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator-(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecSub<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator-(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecSub<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator-(T scalar, const vec<S, T>& v) noexcept
    {
        return glbInternal::vecSub<S, T, glbInternal::useSimd<S, T>::value>::call(vec<S, T>(scalar), v);
    }


    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator*(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecMul<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator*(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecMul<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator*(T scalar, const vec<S, T>& v) noexcept
    {
        return glbInternal::vecMul<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }


    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator/(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecDiv<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator/(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecDiv<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator/(T scalar, const vec<S, T>& v) noexcept
    {
        return glbInternal::vecDiv<S, T, glbInternal::useSimd<S, T>::value>::call(vec<S, T>(scalar), v);
    }


    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator%(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecMod<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator%(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecMod<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }




    // --- Bitwise operators

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator&(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecAnd<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator&(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecAnd<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator&(T scalar, const vec<S, T>& v) noexcept
    {
        return glbInternal::vecAnd<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator|(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecOr<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator|(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecOr<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator|(T scalar, const vec<S, T>& v) noexcept
    {
        return glbInternal::vecOr<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator^(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecXor<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator^(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecXor<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator^(T scalar, const vec<S, T>& v) noexcept
    {
        return glbInternal::vecXor<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator<<(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecShiftLeft<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator<<(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecShiftLeft<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator<<(T scalar, const vec<S, T>& v) noexcept
    {
        return glbInternal::vecShiftLeft<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator>>(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecShiftRight<S, T, glbInternal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator>>(const vec<S, T>& v, T scalar) noexcept
    {
        return glbInternal::vecShiftRight<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator>>(T scalar, const vec<S, T>& v) noexcept
    {
        return glbInternal::vecShiftRight<S, T, glbInternal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }




    template<int S, typename T>
    GLB_INLINE constexpr bool operator==(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecEqual<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr bool operator!=(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return !(a == b);
    }

    template<int S, typename T>
    GLB_INLINE constexpr bool operator<(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecLess<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr bool operator<=(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecLessOrEqual<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr bool operator>(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecGreater<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr bool operator>=(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return glbInternal::vecGreaterOrEqual<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }




    // --- Unary Bitwise operators

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator~(const vec<S, T>& v) noexcept
    {
        return glbInternal::vecNot<S, T, glbInternal::useSimd<S, T>::value>::call(v);
    }
}