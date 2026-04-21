#include <iostream>

#define TMX_FORCE_SIMD_NONE


#include "tmx/internal/vec/type_vec2.hpp"
#include "tmx/internal/vec/type_vec3.hpp"
#include "tmx/internal/vec/type_vec4.hpp"

#include "tmx/internal/mat/type_mat2x2.hpp"
#include "tmx/internal/mat/type_mat3x3.hpp"
#include "tmx/internal/mat/type_mat4x4.hpp"
namespace tmx
{ 
typedef tmx::vec<2, float> Vec2;
typedef tmx::vec<3, float> Vec3;
typedef tmx::vec<4, float> Vec4;

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
    tmx::Mat2x2 a(
        1.0f, 2.0f,
        3.0f, 4.0f
    );

    tmx::Mat2x2 b(
        2.0f, 3.0f,
        4.0f, 3.0f
    );

    logVec(a * tmx::Vec2(5.0f, 6.0f));


    tmx::Mat4x4 move;
    // move[1] = tmx::Vec4(2.0f, 2.0f, 2.0f, 1.0f);

    // logMat(move);
    // logVec4(move[3]);

    // logVec4(move * tmx::Vec4(1.0f, 2.0f, 3.0f, 1.0f));

    // logMat(tmx::Mat4x4(a));


    tmx::Vec3 vec(1.0f);

    



    
    return 0;
}


