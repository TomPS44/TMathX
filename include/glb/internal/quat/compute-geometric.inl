#include <cmath>

namespace glb
{
    namespace glbInternal
    {
        template<typename T, bool useSimd>
        struct quatDot
        {
            GLB_INLINE static constexpr T call(const quat<T>& a, const quat<T>& b) noexcept
            {
                return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
            }
        };


        template<typename T, bool useSimd>
        struct quatLength
        {
            GLB_INLINE static constexpr T call(const quat<T>& q) noexcept
            {
                return std::sqrt(glbInternal::quatDot<T, glbInternal::useSimd<4, T>::value>::call(q, q));
            }
        };


        template<typename T, bool useSimd>
        struct quatNormalize
        {
            GLB_INLINE static constexpr quat<T> call(const quat<T>& q) noexcept
            {
                return q / std::sqrt(glbInternal::quatDot<T, glbInternal::useSimd<4, T>::value>::call(q, q));
            }
        };


        template<typename T, bool useSimd>
        struct quatInverse
        {
            GLB_INLINE static constexpr quat<T> call(const quat<T>& q) noexcept
            {
                // Conjugué x inverse de la longueur au carré 

                return Qua::Conjugate(q) * (1 / glbInternal::quatDot<T, glbInternal::useSimd<4, T>::value>::call(q, q));
            }
        };

        
        
    } // namespace glbInternal
    
    namespace Qua
    {
        template<typename T>
        GLB_INLINE constexpr T Dot(const quat<T>& a, const quat<T>& b) noexcept
        {
            return glbInternal::quatDot<T, glbInternal::useSimd<4, T>::value>::call(a, b);
        }

        template<typename T>
        GLB_INLINE constexpr T Length(const quat<T>& q) noexcept
        {
            return glbInternal::quatLength<T, glbInternal::useSimd<4, T>::value>::call(q);
        }
        template<typename T>
        GLB_INLINE constexpr T LengthSquared(const quat<T>& q) noexcept
        {
            return glbInternal::quatDot<T, glbInternal::useSimd<4, T>::value>::call(q, q);
        }

        template<typename T>
        GLB_INLINE constexpr quat<T> Normalize(const quat<T>& q) noexcept
        {
            return glbInternal::quatNormalize<T, glbInternal::useSimd<4, T>::value>::call(q);
        }

        template<typename T>
        GLB_INLINE constexpr quat<T> Conjugate(const quat<T>& q) noexcept
        {
            return quat<T>(
                q.w, 
                q.x * static_cast<T>(-1),
                q.y * static_cast<T>(-1),
                q.z * static_cast<T>(-1)
            );
        }

        template<typename T>
        GLB_INLINE constexpr quat<T> Inverse(const quat<T>& q) noexcept
        {
            return glbInternal::quatInverse<T, glbInternal::useSimd<4, T>::value>::call(q);
        }

    } // namespace Vec
} // namespace glb