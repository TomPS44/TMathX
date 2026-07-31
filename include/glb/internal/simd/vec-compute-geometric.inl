#include "vec-geometric.inl"

namespace glb
{
    namespace glbInternal
    {

#       if defined(GLB_SIMD_SSE)

        template<>
        struct vecDot<4, float, true>
        {
            GLB_INLINE static float call(const vec<4, float>& a, const vec<4, float>& b) noexcept
            {
                return _mm_cvtss_f32(glbInternal::vecDot__m128(a.reg, b.reg));
            }
        };
        template<>
        struct vecDot<3, float, true>
        {
            GLB_INLINE static float call(const vec<3, float>& a, const vec<3, float>& b) noexcept
            {
                vec<4, float> a0(a);
                vec<4, float> b0(b);

                return _mm_cvtss_f32(glbInternal::vecDot__m128(a0.reg, b0.reg));
            }
        };



        template<>
        struct vecLength<4, float, true>
        {
            GLB_INLINE static float call(const vec<4, float>& v) noexcept
            {
                return _mm_cvtss_f32(glbInternal::vecLength__m128(v.reg));
            }
        };
        template<>
        struct vecDistance<4, float, true>
        {
            GLB_INLINE static float call(const vec<4, float>& a, const vec<4, float>& b) noexcept
            {
                return _mm_cvtss_f32(glbInternal::vecDistance__m128(a.reg, b.reg));
            }
        };


        template<>
        struct vecCross<3, float, true>
        {
            GLB_INLINE static vec<3, float> call(const vec<3, float>& a, const vec<3, float>& b) noexcept
            {
                const vec<4, float> azz(a); 
                const vec<4, float> bzz(b); 

                const __m128 vec4Cross = glbInternal::vecCross__m128(azz.reg, bzz.reg);
                vec<4, float> res4; res4.reg = vec4Cross;

                return vec<3, float>(res4);
            }
        };
        template<>
        struct vecCross<4, float, true>
        {
            GLB_INLINE static vec<4, float> call(const vec<4, float>& a, const vec<4, float>& b) noexcept
            {
                const __m128 vec4Cross = glbInternal::vecCross__m128(a.reg, b.reg);
                vec<4, float> res; res.reg = vec4Cross;

                return res;
            }
        };


#       endif

    }
}