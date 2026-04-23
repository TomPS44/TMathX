#pragma once

#include "tmx/internal/type_quat.hpp"

namespace tmx
{
    namespace Quaternion
    {
        template<typename T>
        TMX_INLINE constexpr T dot(const quat<T>& a, const quat<T>& b) noexcept;

        template<typename T>
        TMX_INLINE constexpr T length(const quat<T>& q) noexcept;
        template<typename T>
        TMX_INLINE constexpr T lengthSquared(const quat<T>& q) noexcept;

        template<typename T>
        TMX_INLINE constexpr quat<T> normalize(const quat<T>& q) noexcept;

    } // namespace Quaternion

} // namespace tmx

#include "tmx/internal/quat/compute_geometric.inl"