#pragma once
#include "tmx/internal/definitions.hpp"
#include "tmx/internal/compute/vec_functors.hpp"
#include "tmx/internal/compute/compute_equal.hpp"

namespace tmx
{
    namespace internal
    {
        template<size_t S, typename T, bool useSimd>
        struct vecAdd {};
        template<size_t S, typename T, bool useSimd>
        struct vecSub {};
        template<size_t S, typename T, bool useSimd>
        struct vecMul {};
        template<size_t S, typename T, bool useSimd>
        struct vecDiv {};
        template<size_t S, typename T, bool useSimd>
        struct vecMod {};
        template<size_t S, typename T, bool useSimd>
        struct vecNeg {};
        template<size_t S, typename T, bool useSimd>
        struct vecAnd {};
        template<size_t S, typename T, bool useSimd>
        struct vecOr {};
        template<size_t S, typename T, bool useSimd>
        struct vecXor {};
        template<size_t S, typename T, bool useSimd>
        struct vecNot {};
        template<size_t S, typename T, bool useSimd>
        struct vecShiftLeft {};
        template<size_t S, typename T, bool useSimd>
        struct vecShiftRight {};

        template<size_t S, typename T, bool isFloating>
        struct vecEqual {};
    


        template<size_t S, typename T>
        struct vecAdd<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a + b; }, 
                    a, b
                );
            }
        };

        template<size_t S, typename T>
        struct vecSub<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a - b; }, 
                    a, b
                );
            }
        };

        template<size_t S, typename T>
        struct vecMul<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a * b; }, 
                    a, b
                );
            }
        };

        template<size_t S, typename T>
        struct vecDiv<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a / b; }, 
                    a, b
                );
            }
        };


        template<size_t S, typename T>
        struct vecMod<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a % b; }, 
                    a, b
                );
            }
        };

        template<size_t S, typename T>
        struct vecNeg<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& v)
            {
                return internal::computeVec_oneElem<S, T>::call(
                    [](T a) -> T
                    { return -a; }, 
                    v
                );
            }
        };



        template<size_t S, typename T>
        struct vecAnd<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (size_t s = 0; s < S; s++)
                {
                    v[s] &= b[s];
                }
                return v;
            }
        };

        template<size_t S, typename T>
        struct vecOr<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (size_t s = 0; s < S; s++)
                {
                    v[s] |= b[s];
                }
                return v;
            }
        };

        template<size_t S, typename T>
        struct vecXor<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (size_t s = 0; s < S; s++)
                {
                    v[s] ^= b[s];
                }
                return v;
            }
        };

        template<size_t S, typename T>
        struct vecNot<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a)
            {
                vec<S, T> v = a;
                for (size_t s = 0; s < S; s++)
                {
                    v[s] = ~v[s];
                }
                return v;
            }
        };

        template<size_t S>
        struct vecNot<S, bool, false>
        {
            TMX_INLINE static constexpr vec<S, bool> call(const vec<S, bool>& a)
            {
                vec<S, bool> v = a;
                for (size_t s = 0; s < S; s++)
                {
                    v[s] = !v[s];
                }
                return v;
            }
        };

        template<size_t S, typename T>
        struct vecShiftLeft<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (size_t s = 0; s < S; s++)
                {
                    v[s] <<= b[s];
                }
                return v;
            }
        };

        template<size_t S, typename T>
        struct vecShiftRight<S, T, false>
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (size_t s = 0; s < S; s++)
                {
                    v[s] >>= b[s];
                }
                return v;
            }
        };


        template<typename T, bool isFloating>
        struct vecEqual<2, T, isFloating>
        {
            TMX_INLINE static constexpr bool call(const vec<2, T>& a, const vec<2, T>& b)
            {
                return 
                    internal::computeEqual<T, isFloating>::call(a.x, b.x) &&
                    internal::computeEqual<T, isFloating>::call(a.y, b.y);

            }
        };
        template<typename T, bool isFloating>
        struct vecEqual<3, T, isFloating>
        {
            TMX_INLINE static constexpr bool call(const vec<3, T>& a, const vec<3, T>& b)
            {
                return 
                    internal::computeEqual<T, isFloating>::call(a.x, b.x) &&
                    internal::computeEqual<T, isFloating>::call(a.y, b.y) &&
                    internal::computeEqual<T, isFloating>::call(a.z, b.z);

            }
        };
        template<typename T, bool isFloating>
        struct vecEqual<4, T, isFloating>
        {
            TMX_INLINE static constexpr bool call(const vec<4, T>& a, const vec<4, T>& b)
            {
                return 
                    internal::computeEqual<T, isFloating>::call(a.x, b.x) &&
                    internal::computeEqual<T, isFloating>::call(a.y, b.y) &&
                    internal::computeEqual<T, isFloating>::call(a.z, b.z) &&
                    internal::computeEqual<T, isFloating>::call(a.w, b.w);

            }
        };
        
        

        



#       if !defined(TMX_SIMD_NONE)
#           include "tmx/internal/compute/compute_vec_simd.inl"

#       endif
    }
}