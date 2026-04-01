#pragma once
#include "tmx/internal/setup.hpp"
#include "__compute_vec.hpp"

namespace tmx
{
    namespace internal
    {
        template<size_t S, typename T, bool useSimd>
        struct vecAdd {};
        template<size_t S, typename T, bool useSimd>
        struct vecSub {};
        template<size_t S, typename T, bool useSimd>
        struct vecMul {};
        template<size_t S, typename T, bool useSimd>
        struct vecDiv {};
        template<size_t S, typename T, bool useSimd>
        struct vecMod {};
    


        template<size_t S, typename T>
        struct vecAdd<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a + b; }, 
                    a, b
                );
            }
        };

        template<size_t S, typename T>
        struct vecSub<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a - b; }, 
                    a, b
                );
            }
        };

        template<size_t S, typename T>
        struct vecMul<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a * b; }, 
                    a, b
                );
            }
        };

        template<size_t S, typename T>
        struct vecDiv<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a / b; }, 
                    a, b
                );
            }
        };


        template<size_t S, typename T>
        struct vecMod<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a % b; }, 
                    a, b
                );
            }
        };




        // ------------------ SIMD ------------------
        // TODO


#if     !defined(TMX_SIMD_NONE)




        template<size_t S>
        struct vecAdd<S, float, true>
        {
            TMX_INLINE static constexpr vec<S, float> call(const vec<S, float>& a, const vec<S, float>& b)
            {
                vec<S, float> res;
                // TODO
            }
        };

#endif

        
    }
}