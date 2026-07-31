#pragma once

#include "../internal/type-quat.h"

namespace glb
{
    namespace Qua
    {
        /** @brief Linearly interpolates between the two Quaternions `start` and `end`, by a factor of `t`. 
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> LerpUnclamped(const quat<T>& start, const quat<T>& end, T t) noexcept;
        /** @brief Linearly interpolates between the two Quaternions `start` and `end`, by a factor of `t`, 
         * which gets clamped in the range of `[0; 1]`. 
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> Lerp(const quat<T>& start, const quat<T>& end, T t) noexcept;

        /** @brief Spherically interpolates between the two Quaternions `start` and `end`, by a factor of `t`. 
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> SlerpUnclamped(const quat<T>& start, const quat<T>& end, T t) noexcept;
        /** @brief Spherically interpolates between the two Quaternions `start` and `end`, by a factor of `t`, 
         * which gets clamped in the range of `[0; 1]`. 
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> Slerp(const quat<T>& start, const quat<T>& end, T t) noexcept;

    } // namespace Vec
    
} // namespace glb

#include "../internal/quat/compute-interpolation.inl"
