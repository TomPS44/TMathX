#pragma once

#include "../internal/type-vec.h"

namespace glb
{
    namespace glbDetail
    {
        template<typename T>
        GLB_INLINE constexpr vec<3, T> unitX_T = vec<3, T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
    
        template<typename T>
        GLB_INLINE constexpr vec<3, T> unitY_T = vec<3, T>(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
    
        template<typename T>
        GLB_INLINE constexpr vec<3, T> unitZ_T = vec<3, T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));

        template<typename T>
        GLB_INLINE constexpr vec<3, T> zero_T = vec<3, T>();

        template<typename T>
        GLB_INLINE constexpr vec<3, T> one_T = vec<3, T>(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));
        
    
    } // namespace glbDetail


    namespace Vec
    {
        template<typename From, typename To>
        GLB_INLINE constexpr vec<2, To> CastTo(const vec<2, From>& v) 
        {
            return vec<2, To>(
                static_cast<To>(v.x),
                static_cast<To>(v.y)
            );
        }
        template<typename From, typename To>
        GLB_INLINE constexpr vec<3, To> CastTo(const vec<3, From>& v) 
        {
            return vec<3, To>(
                static_cast<To>(v.x),
                static_cast<To>(v.y),
                static_cast<To>(v.z)
            );
        }
        template<typename From, typename To>
        GLB_INLINE constexpr vec<4, To> CastTo(const vec<4, From>& v) 
        {
            return vec<4, To>(
                static_cast<To>(v.x),
                static_cast<To>(v.y),
                static_cast<To>(v.z),
                static_cast<To>(v.w)
            );
        }


        template<int S>
        GLB_INLINE constexpr vec<S, int32_t> ToVecInt(const vec<S, float>& v)
        {
            return Vec::CastTo<float, int32_t>(v);
        }
        template<int S>
        GLB_INLINE constexpr vec<S, int64_t> ToVecInt(const vec<S, double>& v)
        {
            return Vec::CastTo<double, int64_t>(v);
        }



        template<int S, typename T>
        GLB_INLINE constexpr vec<2, T> ToVec2(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<2, T>>(v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<3, T> ToVec3(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<3, T>>(v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<4, T> ToVec4(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<4, T>>(v);
        }



        template<int S, typename T>
        GLB_INLINE constexpr vec<2, T> XY(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<2, T>>(v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<3, T> XYZ(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<3, T>>(v);
        }


        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> SplatX(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.x);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> SplatY(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.y);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> SplatZ(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.z);
        }
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> SplatW(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.w);
        }



        GLB_INLINE constexpr vec<3, float> UnitX = glbDetail::unitX_T<float>;
        GLB_INLINE constexpr vec<3, float> UnitY = glbDetail::unitY_T<float>;
        GLB_INLINE constexpr vec<3, float> UnitZ = glbDetail::unitZ_T<float>;
        GLB_INLINE constexpr vec<3, float> Zero = glbDetail::zero_T<float>;
        GLB_INLINE constexpr vec<3, float> One = glbDetail::one_T<float>;
        
        GLB_INLINE constexpr vec<3, int32_t> UnitXi32 = glbDetail::unitX_T<int32_t>;
        GLB_INLINE constexpr vec<3, int32_t> UnitYi32 = glbDetail::unitY_T<int32_t>;
        GLB_INLINE constexpr vec<3, int32_t> UnitZi32 = glbDetail::unitZ_T<int32_t>;
        GLB_INLINE constexpr vec<3, int32_t> Zero_i32 = glbDetail::zero_T<int32_t>;
        GLB_INLINE constexpr vec<3, int32_t> One_i32 = glbDetail::one_T<int32_t>;
    }
}