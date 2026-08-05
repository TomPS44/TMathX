/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




#pragma once

#include "type-dualquat.h"

namespace glb
{
    // A Dual Quaternion of `float`
    using DQuat = dQuat<float>;
    // A Dual Quaternion of `double`
    using DQuat_f64 = dQuat<double>;
}