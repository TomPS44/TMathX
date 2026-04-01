#pragma once

#include "setup.hpp"

namespace tmx
{
    template<size_t S, typename T> struct vec;
    template<size_t R, size_t C, typename T> struct mat;
    template<typename T> struct quat;
    template<typename T> struct dualQuat;



    
    namespace internal
    {
        template<size_t S, typename T>
        struct useSimd 
        {
            static const bool value = false;
        };


#if     defined(TMX_SIMD_SSE)
        template<>
        struct useSimd<4, float>
        {
            static const bool value = true;
        };
#endif

#if     defined(TMX_SIMD_AVX)
        template<>
        struct useSimd<4, double>
        {
            static const bool value = true;
        };
#endif

#if     defined(TMX_SIMD_SSE2)
        template<>
        struct useSimd<4, int>
        {
            static const bool value = true;
        };
#endif

    } // namespace internal
} // namespace tmx