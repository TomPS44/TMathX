#include "tmx/quat/geometric.hpp"
#include <cmath>

namespace tmx
{
    namespace internal
    {
        template<typename T, bool useSimd>
        struct quatLerpUnclamped
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& start, const quat<T>& end, T t) noexcept
            {
                return start + (end - start) * t;
            }
        };

        template<typename T, bool useSimd>
        struct quatSlerpUnclamped
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& start, const quat<T>& end, T t) noexcept
            {
                quat<T> e = end;
                T dot = Quaternion::dot(start, e);

                if (dot < static_cast<T>(0.0))
                {
                    e = -e;
                    dot = -dot;
                }

                if (std::abs(dot) > static_cast<T>(0.9995))
                {
                    return internal::quatLerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
                }

                T omega = std::acos(dot);
                T sinOmega = std::sin(omega);


                T w0 = std::sin((static_cast<T>(1) - t) * omega) / sinOmega;
                T w1 = std::sin(t * omega) / sinOmega;

                return (start * w0) + (e * w1);
            }
        };

    }



    namespace Quaternion
    {    
        template<typename T>
        TMX_INLINE constexpr quat<T> lerp(const quat<T>& start, const quat<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return internal::quatLerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> lerpUnclamped(const quat<T>& start, const quat<T>& end, T t) noexcept
        {
            return internal::quatLerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> slerp(const quat<T>& start, const quat<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return internal::quatSlerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> slerpUnclamped(const quat<T>& start, const quat<T>& end, T t) noexcept
        {
            return internal::quatSlerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
        }

    } // namespace Vector

} // namespace tmx