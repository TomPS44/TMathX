#pragma once

#include "tmx/internal/setup.hpp"

namespace tmx
{
    namespace internal
    {
        template<typename T, bool isFloating>
        struct computeEqual {};


        template<typename T>
        struct computeEqual<T, false>
        {
            TMX_INLINE static constexpr bool call(T a, T b) 
            {
                return a == b;
            }
        };

        template<typename T>
        struct computeEqual<T, true>
        {
            TMX_INLINE static constexpr bool call(T a, T b) 
            {
                return std::abs(b - a) < static_cast<T>(1.0e-06);
            }
        };
    }
} // namespace tmx
