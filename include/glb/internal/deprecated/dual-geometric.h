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
        GLB_INLINE constexpr dQuat<T> Normalize(const dQuat<T>& dq) noexcept;

        template<typename T>
        GLB_INLINE constexpr dQuat<T> Conjugate(const dQuat<T>& dq) noexcept;

        template<typename T>
        GLB_INLINE constexpr dQuat<T> Inverse(const dQuat<T>& dq) noexcept;


        template<typename T>
        GLB_INLINE constexpr quat<T> GetRotation(const dQuat<T>& dq) noexcept;

        template<typename T>
        GLB_INLINE constexpr vec<3, T> GetTranslation(const dQuat<T>& dq) noexcept;

    } // namespace DQua
} // namespace glb

#include "compute-dual-geometric.inl"