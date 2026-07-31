#include "glb/internal/type-vec.h"
#include <cmath>

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Min(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            // return glbInternal::computeVec_twoElem<S, T>::call(std::min, a, b));

            // For some unknown reason, the line above throws an <unresolved overloaded function type>, 
            // so I define the min function myself

            // The same thing apply for the max function 
            
            return glbInternal::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a < b ? a : b; }, 
                a, b);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Min(const vec<S, T>& v, T scalar) noexcept
        {
            // return glbInternal::computeVec_twoElem<S, T>::call(std::min, v, vec<S, T>(scalar));
            return glbInternal::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a < b ? a : b; }, 
                v, vec<S, T>(scalar));
        }


        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Max(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            // return glbInternal::computeVec_twoElem<S, T>::call(std::max, a, b));
            return glbInternal::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a > b ? a : b; }, 
                a, b);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Max(const vec<S, T>& v, T scalar) noexcept
        {
            // return glbInternal::computeVec_twoElem<S, T>::call(std::max, v, vec<S, T>(scalar));
            return glbInternal::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a > b ? a : b; }, 
                v, vec<S, T>(scalar));
        }


        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Abs(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::abs, v);
        }


        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Clamp(const vec<S, T>& v, const vec<S, T>& minVal, const vec<S, T>& maxVal) noexcept
        {
            return Vec::Min(Vec::Max(v, minVal), maxVal);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Clamp(const vec<S, T>& v, T minVal, T maxVal) noexcept
        {
            return Vec::Min(Vec::Max(v, vec<S, T>(minVal)), vec<S, T>(maxVal));
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Clamp01(const vec<S, T>& v) noexcept
        {
            return Vec::Min(Vec::Max(v, static_cast<T>(0)), static_cast<T>(1));
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Saturate(const vec<S, T>& v) noexcept
        {
            return Vec::Clamp01(v);
        }



        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Floor(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::floor, v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Ceil(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::ceil, v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Round(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::round, v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Trunc(const vec<S, T>& v) noexcept
        {
            return glbInternal::computeVec_oneElem<S, T>::call(std::trunc, v);
        }



        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Mod(const vec<S, T>& v, const vec<S, T>& modulus) noexcept
        {
            return glbInternal::computeVec_twoElem<S, T>::call(std::fmod, v, modulus);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Mod(const vec<S, T>& v, T modulus) noexcept
        {
            return glbInternal::computeVec_twoElem<S, T>::call(std::fmod, v, vec<S, T>(modulus));
        }


        

        

    } // namespace Vec
}