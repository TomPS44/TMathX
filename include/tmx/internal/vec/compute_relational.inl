#include "tmx/internal/compute/compute_equal.hpp"
#include <limits>

namespace tmx
{
    namespace Vector
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> greaterThan(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (size_t s = 0; s < S; s++)
                res[s] = a[s] > b[s];
            
            return res;
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> greaterThanOrEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (size_t s = 0; s < S; s++)
                res[s] = a[s] >= b[s];
            
            return res;
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> lessThan(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (size_t s = 0; s < S; s++)
                res[s] = a[s] < b[s];
            
            return res;
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> lessThanOrEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (size_t s = 0; s < S; s++)
                res[s] = a[s] <= b[s];
            
            return res;
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> equal(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            vec<S, bool> res = true;

            for (size_t s = 0; s < S; s++)
                res[s] = internal::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a[s], b[s]);

            return res;
        }

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> notEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept
        {
            return ~equal(a, b);
        }



        template<size_t S>
        TMX_INLINE constexpr bool any(const vec<S, bool>& v) noexcept
        {
            bool res = false;

            for (size_t s = 0; s < 0; s++)
                res = res || v[s];

            return res;
        }

        template<size_t S>
        TMX_INLINE constexpr bool all(const vec<S, bool>& v) noexcept
        {
            bool res = true;

            for (size_t s = 0; s < 0; s++)
                res = res && v[s];

            return res;
        }

    

    } // namespace Vector
    
} // namespace tmx
