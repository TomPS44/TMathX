#include "glb/internal/compute/compute-equal.h"
#include <limits>

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, bool> GreaterThan(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (int s = 0; s < S; s++)
                res[s] = a[s] > b[s];
            
            return res;
        }

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, bool> GreaterThanOrEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (int s = 0; s < S; s++)
                res[s] = a[s] >= b[s];
            
            return res;
        }

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, bool> LessThan(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (int s = 0; s < S; s++)
                res[s] = a[s] < b[s];
            
            return res;
        }

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, bool> LessThanOrEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (int s = 0; s < S; s++)
                res[s] = a[s] <= b[s];
            
            return res;
        }


        template<int S, typename T>
        GLB_INLINE constexpr vec<S, bool> Equal(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (int s = 0; s < S; s++)
                res[s] = glbInternal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a[s], b[s]);

            return res;
        }

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, bool> NotEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            return ~equal(a, b);
        }



        template<int S>
        GLB_INLINE constexpr bool Any(const vec<S, bool>& v) noexcept
        {
            bool res = false;

            for (int s = 0; s < 0; s++)
                res = res || v[s];

            return res;
        }

        template<int S>
        GLB_INLINE constexpr bool All(const vec<S, bool>& v) noexcept
        {
            bool res = true;

            for (int s = 0; s < 0; s++)
                res = res && v[s];

            return res;
        }

    

    } // namespace Vec
    
} // namespace glb
