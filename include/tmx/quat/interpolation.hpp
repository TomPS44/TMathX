#pragma once

#include "tmx/internal/type_quat.hpp"

namespace tmx
{
    namespace Quaternion
    {
        /// @brief Linearly interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at.
        template<size_t S, typename T>
        TMX_INLINE constexpr quat<T> lerpUnclamped(const quat<T>& start, const quat<T>& end, T t) noexcept;
        /// @brief Linearly interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at. Gets clamped between 0 and 1.
        template<size_t S, typename T>
        TMX_INLINE constexpr quat<T> lerp(const quat<T>& start, const quat<T>& end, T t) noexcept;

        /// @brief Spherically interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at.
        template<size_t S, typename T>
        TMX_INLINE constexpr quat<T> slerpUnclamped(const quat<T>& start, const quat<T>& end, T t) noexcept;
        /// @brief Spherically interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at. Gets clamped between 0 and 1.
        template<size_t S, typename T>
        TMX_INLINE constexpr quat<T> slerp(const quat<T>& start, const quat<T>& end, T t) noexcept;

    } // namespace Vector
    
} // namespace tmx

#include "tmx/internal/quat/compute_interpolation.inl"
