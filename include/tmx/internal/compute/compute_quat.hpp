#pragma once

#include "tmx/internal/definitions.hpp"

namespace tmx
{
    namespace internal
    {
        template<typename T, bool useSimd>
        struct quatAdd
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& a, const quat<T>& b) noexcept
            {
                return quat<T>(a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z);
            }
        };
        template<typename T, bool useSimd>
        struct quatSub
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& a, const quat<T>& b) noexcept
            {
                return quat<T>(a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z);
            }
        };
        template<typename T, bool useSimd>
        struct quatDiv
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& v, T scalar) noexcept
            {
                return quat<T>(v.w / scalar, v.x / scalar, v.y / scalar, v.z / scalar);
            }
            TMX_INLINE static constexpr quat<T> call(T scalar, const quat<T>& v) noexcept
            {
                return quat<T>(scalar / v.w, scalar / v.x, scalar / v.y, scalar / v.z);
            }
        };
        template<typename T, bool useSimd>
        struct quatMul
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& a, const quat<T>& b) noexcept
            {
                return quat<T>(
                    a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
                    a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
                    a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
                    a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
                );
            }
            TMX_INLINE static constexpr quat<T> call(const quat<T>& q, T scalar) noexcept
            {
                return quat<T>(q.w * scalar, q.x * scalar, q.y * scalar, q.z * scalar);
            }
            
        };
        


    } // namespace internal
    
} // namespace tmx
