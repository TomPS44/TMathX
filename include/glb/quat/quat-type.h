#pragma once

#include "../internal/type-quat.h"

namespace glb
{
    // A Quaternion of `floats`
    using Quat = quat<float>;
    // A Quaternion of `doubles`
    using QuatHighP = quat<double>;
}