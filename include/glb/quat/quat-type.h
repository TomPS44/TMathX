#pragma once

#include "../internal/type-quat.h"

namespace glb
{
    // A Quaternion of `float`
    using Quat = quat<float>;
    // A Quaternion of `double`
    using Quat_f64 = quat<double>;
}