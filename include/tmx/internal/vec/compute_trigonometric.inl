#include "tmx/internal/compute/vec_functors.hpp"
#include <cmath>

namespace tmx
{
    namespace Vector
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> toRad(const vec<S, T>& v) noexcept
        {
            return v * static_cast<T>(0.01745329251994329576923690768489);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> toDeg(const vec<S, T>& v) noexcept
        {
            return v * static_cast<T>(57.295779513082320876798154814105);
        }



        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> sin(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::sin, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> cos(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::cos, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> tan(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::tan, v);
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> asin(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::asin, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> acos(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::acos, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> atan(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::atan, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> atan2(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            return internal::computeVec_twoElem<S, T>::call(std::atan2, a, b);
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> sinh(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::sinh, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> cosh(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::cosh, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> tanh(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::tanh, v);
        }
        


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> asinh(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::asinh, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> acosh(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::acosh, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> atanh(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::atanh, v);
        }
    }
}