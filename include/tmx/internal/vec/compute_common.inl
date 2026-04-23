#include "tmx/internal/type_vec.hpp"
#include <cmath>

namespace tmx
{
    namespace Vector
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> min(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            // return internal::computeVec_twoElem<S, T>::call(std::min, a, b));

            // For some unknown reason, the line above throws an <unresolved overloaded function type>, 
            // so I define the min function myself

            // The same thing apply for the max function 
            
            return internal::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a < b ? a : b; }, 
                a, b);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> min(const vec<S, T>& v, T scalar) noexcept
        {
            // return internal::computeVec_twoElem<S, T>::call(std::min, v, vec<S, T>(scalar));
            return internal::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a < b ? a : b; }, 
                v, vec<S, T>(scalar));
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> max(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            // return internal::computeVec_twoElem<S, T>::call(std::max, a, b));
            return internal::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a > b ? a : b; }, 
                a, b);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> max(const vec<S, T>& v, T scalar) noexcept
        {
            // return internal::computeVec_twoElem<S, T>::call(std::max, v, vec<S, T>(scalar));
            return internal::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a > b ? a : b; }, 
                v, vec<S, T>(scalar));
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> abs(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::abs, v);
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> clamp(const vec<S, T>& v, const vec<S, T>& minVal, const vec<S, T>& maxVal) noexcept
        {
            return Vector::min(Vector::max(v, minVal), maxVal);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> clamp(const vec<S, T>& v, T minVal, T maxVal) noexcept
        {
            return Vector::min(Vector::max(v, vec<S, T>(minVal)), vec<S, T>(maxVal));
        }



        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> floor(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::floor, v);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> ceil(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::ceil, v);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> round(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::round, v);
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> trunc(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::trunc, v);
        }



        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> mod(const vec<S, T>& v, const vec<S, T>& modulus) noexcept
        {
            return internal::computeVec_twoElem<S, T>::call(std::fmod, v, modulus);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> mod(const vec<S, T>& v, T modulus) noexcept
        {
            return internal::computeVec_twoElem<S, T>::call(std::fmod, v, vec<S, T>(modulus));
        }


        

        

    } // namespace Vector
}