#pragma once
#include "tmx/internal/definitions.hpp"

namespace tmx
{
    namespace internal
    {
        template<size_t S, typename T>
        struct computeVec_oneElem {};

        template<size_t S, typename T>
        struct computeVec_twoElem {};


        template<typename T>
        struct computeVec_oneElem<2, T>
        {
            TMX_INLINE static constexpr vec<3, T> call(T (*Func) (T val), const vec<2, T>& v)
            {
                return vec<2, T>(Func(v.x), Func(v.y));
            }
        };

        template<typename T>
        struct computeVec_oneElem<3, T>
        {
            TMX_INLINE static constexpr vec<3, T> call(T(*Func) (T val), const vec<3, T>& v)
            {
                return vec<3, T>(Func(v.x), Func(v.y), Func(v.z));
            }
        };

        template<typename T>
        struct computeVec_oneElem<4, T>
        {
            TMX_INLINE static constexpr vec<4, T> call(T(*Func) (T val), const vec<4, T>& v)
            {
                return vec<4, T>(Func(v.x), Func(v.y), Func(v.z), Func(v.w));
            }
        };

        


        template<typename T>
        struct computeVec_twoElem<2, T>
        {
            TMX_INLINE static constexpr vec<2, T> call(T(*Func) (T valA, T valB), const vec<2, T>& va, const vec<2, T>& vb)
            {
                return vec<2, T>(Func(va.x, vb.x), Func(va.y, vb.y));
            }
        };

        template<typename T>
        struct computeVec_twoElem<3, T>
        {
            TMX_INLINE static constexpr vec<3, T> call(T(*Func) (T valA, T valB), const vec<3, T>& va, const vec<3, T>& vb)
            {
                return vec<3, T>(Func(va.x, vb.x), Func(va.y, vb.y), Func(va.z, vb.z));
            }
        };

        template<typename T>
        struct computeVec_twoElem<4, T>
        {
            TMX_INLINE static constexpr vec<4, T> call(T(*Func) (T valA, T valB), const vec<4, T>& va, const vec<4, T>& vb)
            {
                return vec<4, T>(Func(va.x, vb.x), Func(va.y, vb.y), Func(va.z, vb.z), Func(va.w, vb.w));
            }
        };
    } 
    
}