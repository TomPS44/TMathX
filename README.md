## Gammalgebra

GLB is a C++ header-only math library made for graphics rendering. <br> It supports `Vectors`, with 2, 3 and 4 components,
`Matrices`, of size 2x2, 3x3 and 4x4, and `Quaternions`. <br>
SIMD instructions are also implemented, for devices supporting SSE, SSE2, or AVX.


```cpp
#include "glb/vec/vec_type.h"
#include "glb/vec/functions.h"

using namespace glb;

int main()
{
    Vec3 a(1.1f, 2.2f, 3.3f);
    Vec3 b(-1.1f, -2.2f, -3.3f);

    Vec3 c = Vec::Cross(a, b);

    return 0;
}
```


Need to update the readme, and the documentation.

