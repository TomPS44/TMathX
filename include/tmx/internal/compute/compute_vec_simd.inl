namespace tmx
{
    namespace internal
    {
                // ------------------ SIMD ------------------
        // TODO


#       if     !defined(TMX_SIMD_NONE)



        template<size_t S>
        struct vecAdd<S, float, true>
        {
            TMX_INLINE static constexpr vec<S, float> call(const vec<S, float>& a, const vec<S, float>& b)
            {
                vec<S, float> res;
                // TODO
            }
        };

        

#       endif
    }
}