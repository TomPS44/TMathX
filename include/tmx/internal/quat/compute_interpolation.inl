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
                quat<T> s = Quaternion::normalize(start);
                quat<T> e = Quaternion::normalize(end);

                T dot = Quaternion::dot(s, e);

                if (dot < static_cast<T>(0.0))
                {
                    e = -e;
                    dot = -dot;
                }

                if (std::abs(dot) > static_cast<T>(0.9995))
                {
                    return internal::quatLerpUnclamped<T, internal::useSimd<4, T>::value>::call(s, e, t);
                }

                T omega = std::acos(dot);
                T sinOmega = std::sin(omega);


                T w0 = std::sin((static_cast<T>(1) - t) * omega) / sinOmega;
                T w1 = std::sin(t * omega) / sinOmega;

                return (s * w0) + (e * w1);
            }
        };

    }

    // namespace Vector
    // {    
    //     template<size_t S, typename T>
    //     TMX_INLINE constexpr vec<S, T> lerp(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
    //     {
    //         // clamps t between 0 and 1
    //         t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

    //         return internal::vecLerpUnclamped<S, T, internal::useSimd<S, T>::value>::call(start, end, t);
    //     }
    //     template<size_t S, typename T>
    //     TMX_INLINE constexpr vec<S, T> lerpUnclamped(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
    //     {
    //         return internal::vecLerpUnclamped<S, T, internal::useSimd<S, T>::value>::call(start, end, t);
    //     }

    //     template<size_t S, typename T>
    //     TMX_INLINE constexpr vec<S, T> slerp(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
    //     {
    //         // clamps t between 0 and 1
    //         t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

    //         return internal::vecSlerpUnclamped<S, T, internal::useSimd<S, T>::value>::call(start, end, t);
    //     }
    //     template<size_t S, typename T>
    //     TMX_INLINE constexpr vec<S, T> slerpUnclamped(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
    //     {
    //         return internal::vecSlerpUnclamped<S, T, internal::useSimd<S, T>::value>::call(start, end, t);
    //     }

    // } // namespace Vector

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