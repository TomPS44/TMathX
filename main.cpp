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


int main()
{
    // std::cout << std::setprecision(10);

    using namespace tmx;

    
    Vec4 start(0.0f, 0.0f, -12.0f, 44.44f);
    Vec4 end(1.0f, 5.0f, 12.0f, -44.44f);

    float t = 0.5f;



    logVec(Vector::slerp(start, end, t));
    
    
    Quat q = Quaternion::normalize(Quat(0.707f, 0.0f, 0.707f, 0.0f));

    
    return 0;
}


