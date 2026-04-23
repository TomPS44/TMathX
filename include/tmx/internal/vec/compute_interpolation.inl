#include "tmx/vec/geometric.hpp"
#include <cmath>

namespace tmx
{
    namespace internal
    {
        template<size_t S, typename T, bool useSimd>
        struct vecLerpUnclamped
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
            {
                return start + (end - start) * t;
            }
        };

        template<size_t S, typename T, bool useSimd>
        struct vecSlerpUnclamped
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
            {
                T dot = Vector::dot(start, end);

                if (std::abs(dot) > static_cast<T>(0.9995))
                {
                    return internal::vecLerpUnclamped<S, T, internal::useSimd<S, T>::value>::call(start, end, t);
                }

                T omega = std::acos(dot);
                T sinOmega = std::sin(omega);


                T w0 = std::sin((static_cast<T>(1) - t) * omega) / sinOmega;
                T w1 = std::sin(t * omega) / sinOmega;

                return (start * w0) + (end * w1);
            }
        };

    }

    namespace Vector
    {    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> lerp(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return internal::vecLerpUnclamped<S, T, internal::useSimd<S, T>::value>::call(start, end, t);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> lerpUnclamped(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
        {
            return internal::vecLerpUnclamped<S, T, internal::useSimd<S, T>::value>::call(start, end, t);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> slerp(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return internal::vecSlerpUnclamped<S, T, internal::useSimd<S, T>::value>::call(start, end, t);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> slerpUnclamped(const vec<S, T>& start, const vec<S, T>& end, T t) noexcept
        {
            return internal::vecSlerpUnclamped<S, T, internal::useSimd<S, T>::value>::call(start, end, t);
        }

    } // namespace Vector
} // namespace tmx