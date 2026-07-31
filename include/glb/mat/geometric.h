#pragma once

#include "../internal/type-mat.h"
#include "../internal/type-vec.h"

namespace glb
{
    namespace Mat
    {
        /**
         * @brief Calculates the determinant of the Matrix `m`.
         */
        template<int R, int C, typename T>
        GLB_INLINE constexpr T Determinant(const mat<R, C, T>& m) noexcept;

        /**
         * @brief Returns the transpose of the Matrix `m`, thus a Matrix of the same size.
         */
        template<int R, int C, typename T>
        GLB_INLINE constexpr mat<C, R, T> Transpose(const mat<R, C, T>& m) noexcept;

        /**
         * @brief Generates a Cross-Product Matrix from the Vec3 `v`.
         */
        template<int R, int C, typename T>
        GLB_INLINE constexpr mat<C, R, T> Cross(const vec<3, T>& v) noexcept;

    } // namespace Mat
    
} // namespace glb

#include "../internal/mat/compute-geometric.inl"