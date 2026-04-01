#include <iostream>

#define TMX_FORCE_SIMD_NONE
#include "tmx/types/vec3_float.hpp"
#include "tmx/types/vec3_int.hpp"


template<typename T>
void logVec3(const tmx::vec<3, T>& vec)
{
    std::cout << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")" << '\n';
}


int main()
{
    tmx::vec3f a(10.0f, 15.5f, 2.0f);
    tmx::vec3f b(0.3f, -0.2f, -0.1f);

    tmx::vec3i i(10, 15, 2);
    
    logVec3(a + b * 2.0f);
    logVec3(i % 2);

    return 0;
}


// TODO: try to make the size of vectors work with template
// so that I dont't have to define the same operators 3 times exctky the same ways 