#pragma once

#include "../internal/definitions.h"
#include <cmath>

namespace glb
{
    namespace Math
    {
        template<typename T>
        GLB_INLINE constexpr T ToRad(T degAngle) noexcept { return degAngle * static_cast<T>(0.0174532925199432957691391462423657899L); };
        template<typename T>
        GLB_INLINE constexpr T ToDeg(T radAngle) noexcept { return radAngle * static_cast<T>(57.295779513082320876654618402312735L); };


        template<typename T>
        GLB_INLINE constexpr T Sin(T radAngle) noexcept { return std::sin(radAngle); }; 
        template<typename T>
        GLB_INLINE constexpr T Cos(T radAngle) noexcept { return std::cos(radAngle); }; 
        template<typename T>
        GLB_INLINE constexpr T Tan(T radAngle) noexcept { return std::tan(radAngle); };
         
        template<typename T>
        GLB_INLINE constexpr T Sinh(T radAngle) noexcept { return std::sinh(radAngle); }; 
        template<typename T>
        GLB_INLINE constexpr T Cosh(T radAngle) noexcept { return std::cosh(radAngle); }; 
        template<typename T>
        GLB_INLINE constexpr T Tanh(T radAngle) noexcept { return std::tanh(radAngle); }; 

    
        template<typename T>
        GLB_INLINE constexpr T Asin(T val) noexcept { return std::asin(val); }; 
        template<typename T>
        GLB_INLINE constexpr T Acos(T val) noexcept { return std::acos(val); }; 
        template<typename T>
        GLB_INLINE constexpr T Atan(T val) noexcept { return std::atan(val); };
        template<typename T>
        GLB_INLINE constexpr T Atan2(T val) noexcept { return std::atan2(val); };
         
        template<typename T>
        GLB_INLINE constexpr T Asinh(T val) noexcept { return std::asinh(val); }; 
        template<typename T>
        GLB_INLINE constexpr T Acosh(T val) noexcept { return std::acosh(val); }; 
        template<typename T>
        GLB_INLINE constexpr T Atanh(T val) noexcept { return std::atanh(val); }; 


        template<typename T>
        GLB_INLINE constexpr T WrapRadAngle_0_2PI(T radAngle) noexcept 
        {
            return 
                radAngle - (
                    static_cast<T>(6.28318530717958647702561791881237241L) * // 2PI
                    std::floor(radAngle * static_cast<T>(0.15915494309189533576888376337251L)) // angle * (1/2PI)
                );
        }
        template<typename T>
        GLB_INLINE constexpr T WrapRadAngle_NPI_PI(T radAngle) noexcept 
        {
            return 
                radAngle - (
                    static_cast<T>(6.28318530717958647702561791881237241L) * // 2PI
                    std::floor((radAngle + static_cast<T>(3.141592653589793238462643383279502884L)) * // angle + PI
                    static_cast<T>(0.15915494309189533576888376337251L)) // 1/2PI
                );
        }

        template<typename T>
        GLB_INLINE constexpr T WrapDegAngle_0_360(T radAngle) noexcept 
        {
            return 
                radAngle - (
                    static_cast<T>(360) * 
                    std::floor(radAngle * static_cast<T>(0.00277777777777777777777777777778L))
                );
        }
        template<typename T>
        GLB_INLINE constexpr T WrapDegAngle_N180_180(T radAngle) noexcept 
        {
            return 
                radAngle - (
                    static_cast<T>(360) * 
                    std::floor((radAngle + static_cast<T>(180)) * 
                    static_cast<T>(0.00277777777777777777777777777778L))
                );
        }

        template<typename T>
        GLB_INLINE constexpr T LerpAngle(T start, T end, T t) noexcept
        {
            const T dist = std::fmod(end - start, static_cast<T>(6.28318530717958647702561791881237241L));
            const T shortDist = std::fmod(static_cast<T>(2) * dist, static_cast<T>(6.28318530717958647702561791881237241L)) - dist;
            
            return start + shortDist * t;
        }
    }
}