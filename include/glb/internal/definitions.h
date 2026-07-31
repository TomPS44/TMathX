#pragma once

#include "setup.h"
#include <cstdint>

namespace glb
{
    template<int S, typename T> struct vec;
    template<int R, int C, typename T> struct mat;
    template<typename T> struct quat;
    template<typename T> struct dQuat;


    
    namespace glbInternal
    {
        
        template<int S, typename T>
        struct useSimd 
        {
            static const bool value = false;
        };
        template<int S, typename T>
        struct simdReg
        {
            typedef struct type
            {
                T reg[S];
            } type;
            
        };


#if     defined(GLB_SIMD_SSE)
        template<>
        struct useSimd<4, float>
        {
            static const bool value = true;
        };
        template<>
        struct useSimd<3, float>
        {
            static const bool value = true;
        };

        template<>
        struct simdReg<4, float>
        {
            typedef __m128 type;
            
        };
#endif

#if     defined(GLB_SIMD_AVX)
        template<>
        struct useSimd<4, double>
        {
            static const bool value = true;
        };

        template<>
        struct simdReg<4, double>
        {
            typedef __m256d type;
            
        };
#endif

#if     defined(GLB_SIMD_SSE2)
        template<>
        struct useSimd<4, int32_t>
        {
            static const bool value = true;
        };
        template<>
        struct simdReg<4, int32_t>
        {
            typedef __m128i type;
        };
#endif


        


        

    } // namespace glbInternal
} // namespace glb