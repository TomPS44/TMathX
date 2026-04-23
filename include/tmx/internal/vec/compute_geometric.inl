#include <cmath>

namespace tmx
{
    namespace internal
    {
        template<size_t S, typename T, bool useSimd>
        struct vecDot
        {};
        template<size_t S, typename T, bool useSimd>
        struct vecCross
        {};

        // Defined below :

        // template<size_t S, typename T, bool useSimd>
        // struct vecLength
        // {};
        // template<size_t S, typename T, bool useSimd>
        // struct vecDistance
        // {};
        // template<size_t S, typename T, bool useSimd>
        // struct vecNormalize
        // {};



        template<typename T, bool useSimd>
        struct vecDot<2, T, useSimd>
        {
            TMX_INLINE static constexpr T call(const vec<2, T>& a, const vec<2, T>& b) noexcept
            {
                return a.x * b.x + a.y * b.y;
            }
        };
        template<typename T, bool useSimd>
        struct vecDot<3, T, useSimd>
        {
            TMX_INLINE static constexpr T call(const vec<3, T>& a, const vec<3, T>& b) noexcept
            {
                return a.x * b.x + a.y * b.y + a.z * b.z;
            }
        };
        template<typename T, bool useSimd>
        struct vecDot<4, T, useSimd>
        {
            TMX_INLINE static constexpr T call(const vec<4, T>& a, const vec<4, T>& b) noexcept
            {
                return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
            }
        };


        template<typename T, bool useSimd>
        struct vecCross<3, T, useSimd>
        {
            TMX_INLINE static constexpr vec<3, T> call(const vec<3, T>& a, const vec<3, T>& b) noexcept
            {
                return vec<3, T>(
                    a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x
                );
            }
        };
        template<typename T, bool useSimd>
        struct vecCross<4, T, useSimd>
        {
            TMX_INLINE static constexpr vec<4, T> call(const vec<4, T>& a, const vec<4, T>& b) noexcept
            {
                return vec<4, T>(
                    a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x,
                    static_cast<T>(0)
                );
            }
        };


        template<size_t S, typename T, bool useSimd>
        struct vecLength
        {
            TMX_INLINE static constexpr T call(const vec<S, T>& v) noexcept
            {
                return std::sqrt(internal::vecDot<S, T, internal::useSimd<S, T>::value>::call(v, v));
            }
        };


        template<size_t S, typename T, bool useSimd>
        struct vecDistance
        {
            TMX_INLINE static constexpr T call(const vec<S, T>& a, const vec<S, T>& b) noexcept
            {
                return Vector::length(b - a);
            }
        };


        template<size_t S, typename T, bool useSimd>
        struct vecNormalize
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& v) noexcept
            {
                return vec<S, T>(
                    v / Vector::length(v)
                );
            }
        };
        
    } // namespace internal
    
    namespace Vector
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr T dot(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            return internal::vecDot<S, T, internal::useSimd<S, T>::value>::call(a, b);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr T length(const vec<S, T>& v) noexcept
        {
            return internal::vecLength<S, T, internal::useSimd<S, T>::value>::call(v);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr T lengthSquared(const vec<S, T>& v) noexcept
        {
            return internal::vecDot<S, T, internal::useSimd<S, T>::value>::call(v, v);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr T distance(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            return internal::vecDistance<S, T, internal::useSimd<S, T>::value>::call(a, b);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr T distanceSquared(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            return internal::vecDot<S, T, internal::useSimd<S, T>::value>::call(b - a, b - a);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> normalize(const vec<S, T>& v) noexcept
        {
            return internal::vecNormalize<S, T, internal::useSimd<S, T>::value>::call(v);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> cross(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            return internal::vecCross<S, T, internal::useSimd<S, T>::value>::call(a, b);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> faceForward(const vec<S, T>& N, const vec<S, T>& I, const vec<S, T>& Nref) noexcept
        {
            return dot(Nref, I) < static_cast<T>(0) ? N : -N;
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> reflect(const vec<S, T>& I, const vec<S, T>& N) noexcept
        {
            return I - N * dot(N, I) * static_cast<T>(2);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> refract(const vec<S, T>& I, const vec<S, T>& N, T eta) noexcept
        {
            T dotVal = dot(N, I);
            T k = static_cast<T>(1) - eta * eta * (static_cast<T>(1) - dotVal * dotVal);

            vec<S, T> res = (k >= static_cast<T>(0)) ? (eta * I - (eta * dotVal + std::sqrt(k) * N)) : vec<S, T>(static_cast<T>(0));
            
            return res;
        }
        

    } // namespace Vector
}