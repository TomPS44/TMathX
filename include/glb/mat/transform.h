#pragma once

#include "rotation.h"
#include "translate.h"
#include "scale.h"

#include "../internal/type-quat.h"
#include "../internal/type-vec.h"

namespace glb
{
    namespace Mat
    {
        /**
         * Generates a 4x4 matrix that is the result of multiplicating the three matrices constructed from `trsl`, `rot` and `scale`,
         * in the order : `translation * rotation * scale`.
         */
        template<typename T>
        GLB_INLINE constexpr mat<4, 4, T> TRS(const vec<3, T>& trsl, const quat<T>& rot, const vec<3, T>& scale) noexcept;

        /**
         * Generates a 4x4 matrix that is the result of multiplicating the three matrices constructed from `trsl`, `rot` and `scale`,
         * in the order : `translation * rotation * scale`.
         */
        template<typename T>
        GLB_INLINE constexpr mat<4, 4, T> TRS(const vec<3, T>& trsl, const vec<3, T>& rot, const vec<3, T>& scale) noexcept;
    }

}

#include "../internal/mat/compute-transform.inl"