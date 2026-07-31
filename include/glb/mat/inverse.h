#pragma once

#include "../internal/type-mat.h"

namespace glb
{
    namespace Mat
    {
        /**
         * @brief Calculates the inverse of any square Matrix `m`.
         * 
         * @attention This function doesn't check if the determinant is 0. In that case, the Matrix will be full of inf. 
         */
        template<int R, int C, typename T>
        GLB_INLINE constexpr mat<R, C, T> Inverse(const mat<R, C, T>& m) noexcept;

        /**
         * @brief Calculates the inverse of any affine Matrix `m`.
         */
        template<int R, int C, typename T>
        GLB_INLINE constexpr mat<R, C, T> AffineInverse(const mat<R, C, T>& m) noexcept;

        /**
         * @brief Calculates the inverse transpose of any square Matrix `m`.
         */
        template<int R, int C, typename T>
        GLB_INLINE constexpr mat<R, C, T> InverseTranspose(const mat<R, C, T>& m) noexcept;

    } // namespace Mat
    
} // namespace glb

#include "../internal/mat/compute-inverse.inl"