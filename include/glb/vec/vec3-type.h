#pragma once

#include "../internal/vec/type-vec3.h"

namespace glb
{
    // A 3D Vector of `float`
    using Vec3 = vec<3, float>;
    // A 3D Vector of `double`
    using Vec3f64 = vec<3, double>;
    // A 3D Vector of `int32_t`
    using Vec3i32 = vec<3, int32_t>; 
    // A 3D Vector of `uint32_t`
    using Vec3u32 = vec<3, uint32_t>; 
    // A 3D Vector of `int64_t`
    using Vec3i64 = vec<3, int64_t>;
    // A 3D Vector of `bool`
    using Vec3b = vec<3, bool>;
}