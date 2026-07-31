#pragma once

#include "../internal/vec/type-vec3.h"

namespace glb
{
    // A 3D Vector of `floats`
    using Vec3 = vec<3, float>;
    // A 3D Vector of `doubles`
    using Vec3HighP = vec<3, double>;
    // A 3D Vector of `int32_t`
    using Vec3Int = vec<3, int32_t>; 
    // A 3D Vector of `int64_t`
    using Vec3Long = vec<3, int64_t>;
    // A 3D Vector of `bool`
    using Vec3Bool = vec<3, bool>;
}