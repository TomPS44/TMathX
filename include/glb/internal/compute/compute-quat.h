#pragma once

#include "glb/internal/definitions.h"

namespace glb
{
    namespace glbInternal
    {
        template<typename T, bool useSimd>
        struct quatAdd
        {
            GLB_INLINE static constexpr quat<T> call(const quat<T>& a, const quat<T>& b) noexcept
            {
                return quat<T>(a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z);
            }
        };
        template<typename T, bool useSimd>
        struct quatSub
        {
            GLB_INLINE static constexpr quat<T> call(const quat<T>& a, const quat<T>& b) noexcept
            {
                return quat<T>(a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z);
            }
        };
        template<typename T, bool useSimd>
        struct quatDiv
        {
            GLB_INLINE static constexpr quat<T> call(const quat<T>& v, T scalar) noexcept
            {
                return quat<T>(v.w / scalar, v.x / scalar, v.y / scalar, v.z / scalar);
            }
            GLB_INLINE static constexpr quat<T> call(T scalar, const quat<T>& v) noexcept
            {
                return quat<T>(scalar / v.w, scalar / v.x, scalar / v.y, scalar / v.z);
            }
        };
        template<typename T, bool useSimd>
        struct quatMul
        {
            GLB_INLINE static constexpr quat<T> call(const quat<T>& a, const quat<T>& b) noexcept
            {
                return quat<T>(
                    a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
                    a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
                    a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
                    a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
                );
            }
            GLB_INLINE static constexpr quat<T> call(const quat<T>& q, T scalar) noexcept
            {
                return quat<T>(q.w * scalar, q.x * scalar, q.y * scalar, q.z * scalar);
            }
            
        };
        


    } // namespace glbInternal
    
} // namespace glb
