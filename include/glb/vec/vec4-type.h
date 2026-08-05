#pragma once

#include "../internal/vec/type-vec4.h"

namespace glb
{
    // A 4D Vector of `float`
    using Vec4 = vec<4, float>;
    // A 4D Vector of `double`
    using Vec4f64 = vec<4, double>;
    // A 4D Vector of `int32_t`
    using Vec4i32 = vec<4, int32_t>; 
    // A 4D Vector of `uint32_t`
    using Vec4u32 = vec<4, uint32_t>; 
    // A 4D Vector of `int64_t`
    using Vec4i64 = vec<4, int64_t>;
    // A 4D Vector of `bool`
    using Vec4b = vec<4, bool>;
}