#pragma once

#include "../internal/type-quat.h"

namespace glb
{
    namespace Qua
    {
        template<typename T>
        GLB_INLINE constexpr T Dot(const quat<T>& a, const quat<T>& b) noexcept;

        template<typename T>
        GLB_INLINE constexpr T Length(const quat<T>& q) noexcept;
        template<typename T>
        GLB_INLINE constexpr T LengthSquared(const quat<T>& q) noexcept;

        template<typename T>
        GLB_INLINE constexpr quat<T> Normalize(const quat<T>& q) noexcept;

        template<typename T>
        GLB_INLINE constexpr quat<T> Conjugate(const quat<T>& q) noexcept;
        
        template<typename T>
        GLB_INLINE constexpr quat<T> Inverse(const quat<T>& q) noexcept;

    } // namespace Qua

} // namespace glb

#include "../internal/quat/compute-geometric.inl"