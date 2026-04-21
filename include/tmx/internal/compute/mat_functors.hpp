#pragma once
#include "tmx/internal/definitions.hpp"

namespace tmx
{
    namespace internal
    {
        template<size_t R, size_t C, typename T>
        struct computeMat_oneElem {} ;

        template<size_t R, size_t C, typename T>
        struct computeMat_twoElem {};


        template<typename T>
        struct computeMat_oneElem<2, 2, T>
        {
            TMX_INLINE static constexpr mat<2, 2, T> call(T (*Func) (T val), const mat<2, 2, T>& m)
            {
                return mat<2, 2, T>(
                    Func(m[0][0]), Func(m[0][1]),
                    Func(m[1][0]), Func(m[1][1])
                );
            }
        };

        template<typename T>
        struct computeMat_twoElem<2, 2, T>
        {
            TMX_INLINE static constexpr mat<2, 2, T> call(T (*Func) (T valA, T valB), const mat<2, 2, T>& ma, const mat<2, 2, T>& mb)
            {
                return mat<2, 2, T>(
                    Func(ma[0][0], mb[0][0]), Func(ma[0][1], mb[0][1]),
                    Func(ma[1][0], mb[1][0]), Func(ma[1][1], mb[1][1])
                );
            }
        };

    } // namespace internal
    
} // namespace tmx
