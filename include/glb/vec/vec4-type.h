#pragma once

#include "../internal/vec/type-vec4.h"

namespace glb
{
    // A 4D Vector of `floats`
    using Vec4 = vec<4, float>;
    // A 4D Vector of `doubles`
    using Vec4HighP = vec<4, double>;
    // A 4D Vector of `int32_t`
    using Vec4Int = vec<4, int32_t>; 
    // A 4D Vector of `int64_t`
    using Vec4Long = vec<4, int64_t>;
    // A 4D Vector of `bool`
    using Vec4Bool = vec<4, bool>;
}