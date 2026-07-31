#include "glb/quat/euler.h"

namespace glb
{
    namespace Mat
    {
        template<typename T>
        GLB_INLINE constexpr mat<4, 4, T> TRS(const vec<3, T>& trsl, const quat<T>& rot, const vec<3, T>& scale) noexcept
        {
            mat<4, 4, T> res = Mat::FromQuat_4x4(rot);

            res[0] *= scale.x; 
            res[1] *= scale.y; 
            res[2] *= scale.z; 

            res[3] = vec<4, T>(trsl, static_cast<T>(1));

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr mat<4, 4, T> TRS(const vec<3, T>& trsl, const vec<3, T>& rot, const vec<3, T>& scale) noexcept
        {
            return Mat::TRS(trsl, Qua::FromEuler(rot), scale);
        }



    }

}