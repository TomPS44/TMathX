#pragma once

#include "../internal/mat/type-mat3x3.h"

namespace glb
{
    // A 3x3 Matrix of `float`
    using Mat3x3 = glb::mat<3, 3, float>;
    // A 3x3 Matrix of `double`
    using Mat3x3f64 = glb::mat<3, 3, double>;
    // // A 3x3 Matrix of `int32_t`
    // using Mat3x3Int = glb::mat<3, 3, int32_t>;
    // // A 3x3 Matrix of `int64_t`
    // using Mat3x3Long = mat<3, 3, int64_t>;
}