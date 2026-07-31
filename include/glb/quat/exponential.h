#pragma once

#include "../internal/type-quat.h"

namespace glb
{
    namespace Qua
    {
        /**
         * @brief Calculates the exponent of the Quaternion `q`, and returns a new Quaternion. 
         * 
         * @retval
         * `Quat(e, (0 0 0))` if the length of the imaginary part is 0, otherwise the exponent calculated with the base formula.
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> Exp(const quat<T>& q) noexcept;
        
        /**
         * @brief Calculates the logarithm of the Quaternion `q`, and returns a new Quaternion. 
         * 
         * @retval
         * `Quat(0, (0 0 0))` if the length of the imaginary part is 0, or the length of the quaternion is 0 
         * (it is supposed not be defined, but a null Quaternion is returned instead), otherwise, the logarithm calculated 
         * with the base formula.
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> Log(const quat<T>& q) noexcept;

        /**
         * @brief Calculates the Quaternion `q` raised to the power `exp`, and returns a new Quaternion.
         * 
         * The formula is Exp(`exp` * Log(`q`))
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> Pow(const quat<T>& q, T exp) noexcept;
        /**
         * @brief Calculates the square root of the Quaternion `q`, and returns a new Quaternion.
         * 
         * The formula is Pow(q, 0.5)
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> Sqrt(const quat<T>& q) noexcept;

    } // namespace Qua
    
} // namespace glb

#include "../internal/quat/compute-exponential.inl"
