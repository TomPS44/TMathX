/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */



 

#pragma once

#include "type-dualquat.h"

namespace glb
{
    namespace DQua
    {
        template<typename T>
        GLB_INLINE constexpr dQuat<T> Exp(const dQuat<T>& q) noexcept;
        
        template<typename T>
        GLB_INLINE constexpr dQuat<T> Log(const dQuat<T>& q) noexcept;

        template<typename T>
        GLB_INLINE constexpr dQuat<T> Pow(const dQuat<T>& q, T exponent) noexcept;
        template<typename T>
        GLB_INLINE constexpr dQuat<T> Sqrt(const dQuat<T>& q) noexcept;

    } // namespace Quaternion
    
} // namespace glb

#include "compute-dual-exponential.inl"
