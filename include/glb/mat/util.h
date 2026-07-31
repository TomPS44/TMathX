#pragma once

#include "../internal/type-mat.h"
#include "glb/vec/util.h"

namespace glb
{
    namespace Vec
    {
        template<typename From, typename To>
        GLB_INLINE constexpr mat<2, 2, To> CastTo(const mat<2, 2, From>& m) 
        {
            return mat<2, 2, To>(
                Vec::CastTo<From, To>(m[0]),
                Vec::CastTo<From, To>(m[1]);
            )
        }
        template<typename From, typename To>
        GLB_INLINE constexpr mat<3, 3, To> CastTo(const mat<3, 3, From>& m) 
        {
            return mat<3, 3, To>(
                Vec::CastTo<From, To>(m[0]),
                Vec::CastTo<From, To>(m[1]),
                Vec::CastTo<From, To>(m[2]);
            )
        }
        template<typename From, typename To>
        GLB_INLINE constexpr mat<4, 4, To> CastTo(const mat<4, 4, From>& m) 
        {
            return mat<4, 4, To>(
                Vec::CastTo<From, To>(m[0]),
                Vec::CastTo<From, To>(m[1]),
                Vec::CastTo<From, To>(m[2]),
                Vec::CastTo<From, To>(m[3]);
            )
        }



        template<int R, int C, typename T>
        GLB_INLINE constexpr mat<2, 2, T> ToMat2x2(const mat<R, C, T>& m) noexcept
        {
            return static_cast<mat<2, 2, T>>(m);
        }
        template<int R, int C, typename T>
        GLB_INLINE constexpr mat<3, 3, T> ToMat3x3(const mat<R, C, T>& m) noexcept
        {
            return static_cast<mat<3, 3, T>>(m);
        }
        template<int R, int C, typename T>
        GLB_INLINE constexpr mat<4, 4, T> ToMat4x4(const mat<R, C, T>& m) noexcept
        {
            return static_cast<mat<4, 4, T>>(m);
        }

    }

    
}