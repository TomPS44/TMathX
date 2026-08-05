#pragma once

#include "setup.h"
#include <cstdint>

namespace glb
{
    /**
     * @brief A vector of size `S` storing values of type `T`.
     * 
     * To create an alias, use :
     * 
     * ```cpp
     * typedef vec<%SIZE%, %TYPE%> %NAME%;
     * or
     * using %NAME% = vec<%SIZE%, %TYPE%>;
     * 
     * 
     * Ex: 
     * using Vec8c = vec<8, char>;
     * ```
     */
    template<int S, typename T> struct vec;
    /**
     * @brief A matrix of size `R x C` storing values of type `T`.
     * 
     * To create an alias, use :
     * 
     * ```cpp
     * typedef mat<%ROWS%, %COLS%, %TYPE> %NAME%;
     * or
     * using %NAME% = mat<%ROWS%, %COLS%, %TYPE>;
     * 
     * 
     * Ex: 
     * using Mat6x8b = mat<6, 8, bool>;
     * ```
     */
    template<int R, int C, typename T> struct mat;
    /**
     * @brief A Quaternion storing values of type `T`.
     * 
     * To create an alias, use :
     * 
     * ```cpp
     * typedef quat<%TYPE%> %NAME%;
     * or
     * using %NAME% = quat<%TYPE%>;
     * 
     * 
     * Ex: 
     * using QuatHighHighP = quat<long double>;
     * ```
     */
    template<typename T> struct quat;
    /**
     * @brief A Dual Quaternion of size `S` storing values of type `T`.
     * 
     * To create an alias, use :
     * 
     * ```cpp
     * typedef dQuat<%TYPE%> %NAME%;
     * or
     * using %NAME% = dQuat<%TYPE%>;
     * 
     * 
     * Ex: 
     * using DQuatf32 = dQuat<float>;
     * ```
     */
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