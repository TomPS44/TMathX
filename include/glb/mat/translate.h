#pragma once

#include "../internal/type-mat.h"
#include "../internal/type-vec.h"

namespace glb
{
    namespace Mat
    {
        template<typename T>
        GLB_INLINE constexpr mat<4, 4, T> Translate(const vec<3, T>& trsl) noexcept;

    } // namespace Mat
    
} // namespace glb

#include "../internal/mat/compute-translate.inl"