#pragma once

#include <stdint.h>


#if defined(_MSC_VER)
#   define TMX_COMPILER_MSVC

#elif defined(__clang__)
#   define TMX_COMPILER_CLANG

#elif defined(__GNUC__) 
#   define TMX_COMPILER_GCC

#endif

// #if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64)
// #   define TMX_PLATFORM_AMD64

// #elif defined(__arm__) || defined(_M_ARM)
// #   define TMX_PLATFORM_ARM

// #elif defined(__aarch64__) || defined(_M_ARM64)
// #   define TMX_PLATFORM_ARM64

// #endif

#if defined(__ANDROID__)
#   define TMX_PLATFORM_ANDROID

#elif defined(__linux__)
#   define TMX_PLATFORM_LINUX

#elif defined(__WIN32) || defined(__WIN64) || defined(__WIN16)
#   define TMX_PLATFORM_WINDOWS

#elif defined(__unix__) || defined(__unix)
#   define TMX_PLATFORM_UNIX

#elif defined(__APPLE__)
#   define TMX_PLATFORM_APPLE

#endif



#if !defined(TMX_FORCE_SIMD_NONE)
#   if defined(TMX_FORCE_SIMD_AVX) || defined(__AVX2__) || defined(__AVX__)
#       define TMX_SIMD_AVX
#       define TMX_SIMD_SSE2
#       define TMX_SIMD_SSE

#   elif defined(TMX_FORCE_SIMD_SSE2) || defined(__SSE2__)
#       define TMX_SIMD_SSE2 
#       define TMX_SIMD_SSE 

#   elif defined(TMX_FORCE_SIMD_SSE) || defined(__SSE__)
#       define TMX_SIMD_SSE

#   else 
#       define TMX_SIMD_NONE

#   endif

#else 
#   define TMX_SIMD_NONE

// #   elif defined(TMX_FORCE_SIMD_SSE4_2) || defined(__SSE4_2__)
// #       define TMX_SIMD_AVX

#endif







#define TMX_INLINE inline // or change to forceinline


