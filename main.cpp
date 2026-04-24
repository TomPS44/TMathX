#include <iostream>
#include <iomanip>

#define TMX_FORCE_SIMD_NONE

#include "tmx/vec/vec_type.hpp"
#include "tmx/vec/functions.hpp"

#include "tmx/internal/mat/type_mat2x2.hpp"
#include "tmx/internal/mat/type_mat3x3.hpp"
#include "tmx/internal/mat/type_mat4x4.hpp"

#include "tmx/quat/quat_type.hpp"
#include "tmx/quat/dualquat_type.hpp"

#include "tmx/quat/interpolation.hpp"
#include "tmx/quat/geometric.hpp"
#include "tmx/quat/angle.hpp"


namespace tmx
{ 
typedef tmx::mat<2, 2, float> Mat2x2;
typedef tmx::mat<3, 3, float> Mat3x3;
typedef tmx::mat<4, 4, float> Mat4x4;
}



template<size_t S, typename T>
void logVec(const tmx::vec<S, T>& vec)
{
    std::cout << "(";
    for (size_t i = 0; i < S - 1; i++)
    {
        std::cout << vec.values[i] << ", ";
    }
    std::cout << vec.values[S - 1];
    std::cout << ")" << '\n';
}

template<size_t R, size_t C, typename T>
void logMat(const tmx::mat<R, C, T>& mat)
{
    for (size_t r = 0; r < R; r++)
    {
        for (size_t c = 0; c < C; c++)
        {
            std::cout << mat[c][r] << " ";
        }
        std::cout << '\n';
    }
}

template<typename T>
void logQuat(const tmx::quat<T>& qua)
{
    std::cout << "(";
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << qua.values[i] << ", ";
    }
    std::cout << qua.values[3];
    std::cout << ")" << '\n';
}




int main()
{
    // std::cout << std::setprecision(30);

    using namespace tmx;


    QuatHighP q = Quaternion::slerp(Quaternion::fromEulerYXZ(10.0, 20.0, 30.0), Quaternion::fromEulerYXZ(45.0, -30.0, 60.0), 0.5);

    logVec(Quaternion::toEulerYXZ(q));

    // Need to make update the slerp for vectors (unit vectors)

    // For vectors, need to implement : 
    // - Smooth Damp,
    // - Move Towards
    // - Step (for single numbers too)
    // - Smooth Step (for single numbers too)
    // - Smoother Step (for single numbers too)
    // - Clamp Magnitude
    // - Inverse Lerp (for single numbers too)
    
    
    return 0;
}


