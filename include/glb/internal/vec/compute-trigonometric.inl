#include "glb/internal/compute/vec-functors.h"
#include <cmath>

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> ToRad(const vec<S, T>& v) noexcept
        {
            return v * static_cast<T>(0.01745329251994329576923690768489);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> ToDeg(const vec<S, T>& v) noexcept
        {
            return v * static_cast<T>(57.295779513082320876798154814105);
        }



        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Sin(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::sin, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Cos(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::cos, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Tan(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::tan, v);
        }


        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Asin(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::asin, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Acos(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::acos, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Atan(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::atan, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Atan2(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            return glbInternal::computeVec_twoElem<S, T>::call(std::atan2, a, b);
        }


        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Sinh(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::sinh, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Cosh(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::cosh, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Tanh(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::tanh, v);
        }
        


        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Asinh(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::asinh, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Acosh(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::acosh, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Atanh(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::atanh, v);
        }
    }
}