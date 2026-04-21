#pragma once 
#include "tmx/internal/compute/mat_functors.hpp"

namespace tmx
{
    namespace internal
    {
        template<size_t R, size_t C, typename T, bool useSimd>
        struct matAdd {};
        template<size_t R, size_t C, typename T, bool useSimd>
        struct matSub {};
        template<size_t R, size_t C, typename T, bool useSimd>
        struct matMul {};
        template<size_t R, size_t C, typename T, bool useSimd>
        struct matDiv {};
        template<size_t R, size_t C, typename T, bool useSimd>
        struct matNeg {};

        template<size_t R, size_t C, typename T>
        struct matEqual {};



        template<size_t R, size_t C, typename T>
        struct matAdd<R, C, T, false>
        {
            TMX_INLINE static constexpr mat<R, C, T> call(const mat<R, C, T>& a, const mat<R, C, T>& b)
            {
                return internal::computeMat_twoElem<R, C, T>::call(
                    [](T a, T b) -> T
                    { return a + b; },
                    a, b
                );
            }

            TMX_INLINE static constexpr mat<2, 2, T> call(const mat<2, 2, T>& m, T scalar)
            {
                return mat<2, 2, T>(
                    m[0] + scalar,
                    m[1] + scalar
                );
            }
            TMX_INLINE static constexpr mat<3, 3, T> call(const mat<3, 3, T>& m, T scalar)
            {
                return mat<3, 3, T>(
                    m[0] + scalar,
                    m[1] + scalar,
                    m[2] + scalar
                );
            }
            TMX_INLINE static constexpr mat<4, 4, T> call(const mat<4, 4, T>& m, T scalar)
            {
                return mat<4, 4, T>(
                    m[0] + scalar,
                    m[1] + scalar,
                    m[2] + scalar,
                    m[3] + scalar
                );
            }
        };

        template<size_t R, size_t C, typename T>
        struct matSub<R, C, T, false>
        {
            TMX_INLINE static constexpr mat<R, C, T> call(const mat<R, C, T>& a, const mat<R, C, T>& b)
            {
                return internal::computeMat_twoElem<R, C, T>::call(
                    [](T a, T b) -> T
                    { return a - b; },
                    a, b
                );
            }

            TMX_INLINE static constexpr mat<2, 2, T> call(const mat<2, 2, T>& m, T scalar)
            {
                return mat<2, 2, T>(
                    m[0] - scalar,
                    m[1] - scalar
                );
            }
            TMX_INLINE static constexpr mat<3, 3, T> call(const mat<3, 3, T>& m, T scalar)
            {
                return mat<3, 3, T>(
                    m[0] - scalar,
                    m[1] - scalar,
                    m[2] - scalar
                );
            }
            TMX_INLINE static constexpr mat<4, 4, T> call(const mat<4, 4, T>& m, T scalar)
            {
                return mat<4, 4, T>(
                    m[0] - scalar,
                    m[1] - scalar,
                    m[2] - scalar,
                    m[3] - scalar
                );
            }
        };

        template<typename T>
        struct matMul<2, 2, T, false>
        {
            TMX_INLINE static constexpr mat<2, 2, T> call(const mat<2, 2, T>& a, const mat<2, 2, T>& b)
            {
                return mat<2, 2, T>(
                    a[0][0] * b[0][0] + a[1][0] * b[0][1], 
                    a[0][0] * b[1][0] + a[1][0] * b[1][1],
                    a[0][1] * b[0][0] + a[1][1] * b[0][1],
                    a[0][1] * b[1][0] + a[1][1] * b[1][1]
                );
            }
            

            TMX_INLINE static constexpr mat<2, 2, T> call(const mat<2, 2, T>& m, T scalar)
            {
                return mat<2, 2, T>(
                    m[0] * scalar,
                    m[1] * scalar
                );
            }

            TMX_INLINE static constexpr typename mat<2, 2, T>::colType call(const mat<2, 2, T>& m, const typename mat<2, 2, T>::colType& v)
            {
                // return typename mat<2, 2, T>::colType(
                //     v[0] * m[0][0] + v[1] * m[0][1],
                //     v[0] * m[1][0] + v[1] * m[1][1]
                // );
                return m[0] * v.x + m[1] * v.y;
            }
        };
        template<typename T>
        struct matMul<3, 3, T, false>
        { 
            TMX_INLINE static constexpr mat<3, 3, T> call(const mat<3, 3, T>& m, T scalar)
            {
                return mat<3, 3, T>(
                    m[0] * scalar,
                    m[1] * scalar,
                    m[2] * scalar
                );
            }

            TMX_INLINE static constexpr typename mat<3, 3, T>::colType call(const mat<3, 3, T>& m, const typename mat<3, 3, T>::colType& v)
            {
                // return typename mat<3, 3, T>::colType(
                //     v[0] * m[0][0] + v[1] * m[0][1] + v[2] * m[0][2],
                //     v[0] * m[1][0] + v[1] * m[1][1] + v[2] * m[1][2],
                //     v[0] * m[2][0] + v[1] * m[2][1] + v[2] * m[2][2]
                // );
                return m[0] * v.x + m[1] * v.y + m[2] * v.z;
            }

            TMX_INLINE static constexpr mat<3, 3, T> call(const mat<3, 3, T>& a, const mat<3, 3, T>& b)
            {
                // return mat<3, 3, T>(
                //     a[0][0] * b[0][0] + a[1][0] * b[0][1] + a[2][0] * b[0][2], 
                //     a[0][1] * b[0][0] + a[1][1] * b[0][1] + a[2][1] * b[0][2], 
                //     a[0][2] * b[0][0] + a[1][2] * b[0][1] + a[2][2] * b[0][2], 
                    
                //     a[0][0] * b[1][0] + a[1][0] * b[1][1] + a[2][0] * b[1][2], 
                //     a[0][1] * b[1][0] + a[1][1] * b[1][1] + a[2][1] * b[1][2], 
                //     a[0][2] * b[1][0] + a[1][2] * b[1][1] + a[2][2] * b[1][2], 
                    
                //     a[0][0] * b[2][0] + a[1][0] * b[2][1] + a[2][0] * b[2][2],
                //     a[0][1] * b[2][0] + a[1][1] * b[2][1] + a[2][1] * b[2][2], 
                //     a[0][2] * b[2][0] + a[1][2] * b[2][1] + a[2][2] * b[2][2]
                // );

                mat<3, 3, T> res;

                typename mat<3, 3, T>::colType vec;

                vec = a[0] * b[0][0];
                vec += a[1] * b[0][1];
                vec += a[2] * b[0][2];

                res[0] = vec;

                vec = a[0] * b[1][0];
                vec += a[1] * b[1][1];
                vec += a[2] * b[1][2];

                res[1] = vec;

                vec = a[0] * b[2][0];
                vec += a[1] * b[2][1];
                vec += a[2] * b[2][2];

                res[2] = vec;

                
                return res;
                
            }
        };
        
        template<typename T>
        struct matMul<4, 4, T, false>
        { 
            TMX_INLINE static constexpr typename mat<4, 4, T>::colType call(const mat<4, 4, T>& m, const typename mat<4, 4, T>::colType& v)
            {
                // return typename mat<4, 4, T>::colType(
                    // v[0] * m[0][0] + v[1] * m[0][1] + v[2] * m[0][2] + v[3] * m[0][3],
                    // v[0] * m[1][0] + v[1] * m[1][1] + v[2] * m[1][2] + v[3] * m[1][3],
                    // v[0] * m[2][0] + v[1] * m[2][1] + v[2] * m[2][2] + v[3] * m[2][3],
                    // v[0] * m[3][0] + v[1] * m[3][1] + v[2] * m[3][2] + v[3] * m[3][3]
                // );
                return m[0] * v.x + m[1] * v.y + m[2] * v.z + m[3] * v.w;
            }

            TMX_INLINE static constexpr mat<4, 4, T> call(const mat<4, 4, T>& m, T scalar)
            {
                return mat<4, 4, T>(
                    m[0] * scalar,
                    m[1] * scalar,
                    m[2] * scalar,
                    m[3] * scalar
                );
            }

            TMX_INLINE static constexpr mat<4, 4, T> call(const mat<4, 4, T>& a, const mat<4, 4, T>& b)
            {
                // return mat<4, 4, T>(
                //     a[0][0] * b[0][0] + a[1][0] * b[0][1] + a[2][0] * b[0][2] + a[3][0] * b[0][3],
                //     a[0][1] * b[0][0] + a[1][1] * b[0][1] + a[2][1] * b[0][2] + a[3][1] * b[0][3], 
                //     a[0][2] * b[0][0] + a[1][2] * b[0][1] + a[2][2] * b[0][2] + a[3][2] * b[0][3], 
                //     a[0][3] * b[0][0] + a[1][3] * b[0][1] + a[2][3] * b[0][2] + a[3][3] * b[0][3],

                //     a[0][0] * b[1][0] + a[1][0] * b[1][1] + a[2][0] * b[1][2] + a[3][0] * b[1][3], 
                //     a[0][1] * b[1][0] + a[1][1] * b[1][1] + a[2][1] * b[1][2] + a[3][1] * b[1][3], 
                //     a[0][2] * b[1][0] + a[1][2] * b[1][1] + a[2][2] * b[1][2] + a[3][2] * b[1][3], 
                //     a[0][3] * b[1][0] + a[1][3] * b[1][1] + a[2][3] * b[1][2] + a[3][3] * b[1][3], 

                //     a[0][0] * b[2][0] + a[1][0] * b[2][1] + a[2][0] * b[2][2] + a[3][0] * b[2][3], 
                //     a[0][1] * b[2][0] + a[1][1] * b[2][1] + a[2][1] * b[2][2] + a[3][1] * b[2][3], 
                //     a[0][2] * b[2][0] + a[1][2] * b[2][1] + a[2][2] * b[2][2] + a[3][2] * b[2][3], 
                //     a[0][3] * b[2][0] + a[1][3] * b[2][1] + a[2][3] * b[2][2] + a[3][3] * b[2][3], 

                //     a[0][0] * b[3][0] + a[1][0] * b[3][1] + a[2][0] * b[3][2] + a[3][0] * b[3][3], 
                //     a[0][1] * b[3][0] + a[1][1] * b[3][1] + a[2][1] * b[3][2] + a[3][1] * b[3][3], 
                //     a[0][2] * b[3][0] + a[1][2] * b[3][1] + a[2][2] * b[3][2] + a[3][2] * b[3][3], 
                //     a[0][3] * b[3][0] + a[1][3] * b[3][1] + a[2][3] * b[3][2] + a[3][3] * b[3][3]
                // );    
                
                mat<4, 4, T> res;

                typename mat<4, 4, T>::colType vec;

                vec = a[0] * b[0][0];
                vec += a[1] * b[0][1];
                vec += a[2] * b[0][2];
                vec += a[3] * b[0][3];

                res[0] = vec;

                vec = a[0] * b[1][0];
                vec += a[1] * b[1][1];
                vec += a[2] * b[1][2];
                vec += a[3] * b[1][3];

                res[1] = vec;

                vec = a[0] * b[2][0];
                vec += a[1] * b[2][1];
                vec += a[2] * b[2][2];
                vec += a[3] * b[2][3];

                res[2] = vec;

                vec = a[0] * b[3][0];
                vec += a[1] * b[3][1];
                vec += a[2] * b[3][2];
                vec += a[3] * b[3][3];

                res[3] = vec;

                
                return res;
            }
        };
        

        template<size_t R, size_t C, typename T>
        struct matDiv<R, C, T, false>
        {
            TMX_INLINE static constexpr mat<2, 2, T> call(const mat<2, 2, T>& m, T scalar)
            {
                return mat<2, 2, T>(
                    m[0] / scalar,
                    m[1] / scalar
                );
            }
            TMX_INLINE static constexpr mat<3, 3, T> call(const mat<3, 3, T>& m, T scalar)
            {
                return mat<3, 3, T>(
                    m[0] / scalar,
                    m[1] / scalar,
                    m[2] / scalar
                );
            }
            TMX_INLINE static constexpr mat<4, 4, T> call(const mat<4, 4, T>& m, T scalar)
            {
                return mat<4, 4, T>(
                    m[0] / scalar,
                    m[1] / scalar,
                    m[2] / scalar,
                    m[3] / scalar
                );
            }
        };
    



        template<size_t R, size_t C, typename T>
        struct matNeg<R, C, T, false>
        {
            TMX_INLINE static constexpr mat<R, C, T> call(const mat<R, C, T>& m)
            {
                return internal::computeMat_oneElem<R, C, T>::call(
                    [](T a) -> T
                    { return -a; },
                    m
                );
            }
        };




        template<typename T>
        struct matEqual<2, 2, T>
        {
            TMX_INLINE static constexpr bool call(const mat<2, 2, T>& a, const mat<2, 2, T>& b)
            {
                return a[0] == b[0] && a[1] == b[1]; 
            }
        };
        template<typename T>
        struct matEqual<3, 3, T>
        {
            TMX_INLINE static constexpr bool call(const mat<3, 3, T>& a, const mat<3, 3, T>& b)
            {
                return a[0] == b[0] && a[1] == b[1] && a[2] == b[2]; 
            }
        };
        template<typename T>
        struct matEqual<4, 4, T>
        {
            TMX_INLINE static constexpr bool call(const mat<4, 4, T>& a, const mat<4, 4, T>& b)
            {
                return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]; 
            }
        };
    }
}