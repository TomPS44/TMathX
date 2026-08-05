#pragma once

#include "../internal/vec/type-vec2.h"

namespace glb
{
    // A 2D Vector of `float`
    using Vec2 = vec<2, float>;
    // A 2D Vector of `double`
    using Vec2f64 = vec<2, double>;
    // A 2D Vector of `int32_t`
    using Vec2i32 = vec<2, int32_t>; 
    // A 2D Vector of `uint32_t`
    using Vec2u32 = vec<2, uint32_t>; 
    // A 2D Vector of `int64_t`
    using Vec2i64 = vec<2, int64_t>; 
    // A 2D Vector of `bool`
    using Vec2b = vec<2, bool>;
}