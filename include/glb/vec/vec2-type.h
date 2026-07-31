#pragma once

#include "../internal/vec/type-vec2.h"

namespace glb
{
    // A 2D Vector of `floats`
    using Vec2 = vec<2, float>;
    // A 2D Vector of `doubles`
    using Vec2HighP = vec<2, double>;
    // A 2D Vector of `int32_t`
    using Vec2Int = vec<2, int32_t>; 
    // A 2D Vector of `int64_t`
    using Vec2Long = vec<2, int64_t>; 
    // A 2D Vector of `bool`
    using Vec2Bool = vec<2, bool>;
}