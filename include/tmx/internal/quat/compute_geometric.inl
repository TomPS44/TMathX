#include <cmath>

namespace tmx
{
    namespace internal
    {
        template<typename T, bool useSimd>
        struct quatDot
        {
            TMX_INLINE static constexpr T call(const quat<T>& a, const quat<T>& b) noexcept
            {
                return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
            }
        };


        template<typename T, bool useSimd>
        struct quatLength
        {
            TMX_INLINE static constexpr T call(const quat<T>& q) noexcept
            {
                return std::sqrt(internal::quatDot<T, internal::useSimd<4, T>::value>::call(q, q));
            }
        };


        template<typename T, bool useSimd>
        struct quatNormalize
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& q) noexcept
            {
                return q / std::sqrt(internal::quatDot<T, internal::useSimd<4, T>::value>::call(q, q));
            }
        };

        
        
    } // namespace internal
    
    namespace Quaternion
    {
        template<typename T>
        TMX_INLINE constexpr T dot(const quat<T>& a, const quat<T>& b) noexcept
        {
            return internal::quatDot<T, internal::useSimd<4, T>::value>::call(a, b);
        }

        template<typename T>
        TMX_INLINE constexpr T length(const quat<T>& q) noexcept
        {
            return internal::quatLength<T, internal::useSimd<4, T>::value>::call(q);
        }
        template<typename T>
        TMX_INLINE constexpr T lengthSquared(const quat<T>& q) noexcept
        {
            return internal::quatDot<T, internal::useSimd<4, T>::value>::call(q, q);
        }

        template<typename T>
        TMX_INLINE constexpr quat<T> normalize(const quat<T>& q) noexcept
        {
            return internal::quatNormalize<T, internal::useSimd<4, T>::value>::call(q);
        }

    } // namespace Vector
} // namespace tmx