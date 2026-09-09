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
     * using NAME = glbVec_T<SIZE, TYPE>;
     * 
     * 
     * Ex: 
     * using Vec8c = glbVec_T<8, char>;
     * ```
     */
    template<int S, typename T> struct glbVec_T;
    /**
     * @brief A matrix of size `R x C` storing values of type `T`.
     * 
     * To create an alias, use :
     * 
     * ```cpp
     * typedef glbMat_T<%ROWS%, %COLS%, %TYPE> %NAME%;
     * or
     * using %NAME% = glbMat_T<%ROWS%, %COLS%, %TYPE>;
     * 
     * 
     * Ex: 
     * using Mat6x8b = glbMat_T<6, 8, bool>;
     * ```
     */
    template<int R, int C, typename T> struct glbMat_T;
    /**
     * @brief A Quaternion storing values of type `T`.
     * 
     * To create an alias, use :
     * 
     * ```cpp
     * typedef glbQuat_T<%TYPE%> %NAME%;
     * or
     * using %NAME% = glbQuat_T<%TYPE%>;
     * 
     * 
     * Ex: 
     * using QuatHighHighP = glbQuat_T<long double>;
     * ```
     */
    template<typename T> struct glbQuat_T;
    /**
     * @brief A Dual Quaternion of size `S` storing values of type `T`.
     * 
     * To create an alias, use :
     * 
     * ```cpp
     * typedef glbDQuat_T<%TYPE%> %NAME%;
     * or
     * using %NAME% = glbDQuat_T<%TYPE%>;
     * 
     * 
     * Ex: 
     * using DQuatf32 = glbDQuat_T<float>;
     * ```
     */
    template<typename T> struct glbDQuat_T;


    
    namespace glbIntern
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


        


        

    } // namespace glbIntern
} // namespace glb