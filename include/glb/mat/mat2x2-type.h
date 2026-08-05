#pragma once

#include "../internal/mat/type-mat2x2.h"

namespace glb
{
    // A 2x2 Matrix of `float`
    using Mat2x2 = mat<2, 2, float>;
    // A 2x2 Matrix of `double`
    using Mat2x2f64 = mat<2, 2, double>;
    // // A 2x2 Matrix of `int32_t`
    // using Mat2x2Int = mat<2, 2, int32_t>;
    // // A 2x2 Matrix of `int64_t`
    // using Mat2x2Long = mat<2, 2, int64_t>;
}