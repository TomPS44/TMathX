/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */





 

#include "../type-quat.h"
#include "glb/quat/geometric.h"

namespace glb
{
    namespace DQua
    {
        template<typename T>
        GLB_INLINE constexpr dQuat<T> Normalize(const dQuat<T>& dq) noexcept
        {
            const T realL = Qua::Length(dq.real);

            const quat<T> normReal = dq.real / realL;
            const quat<T> normDual = dq.dual / realL; 

            return dQuat<T>(
                normReal,
                normDual - normReal * (Qua::Dot(normReal, normDual))
            );
        }

        template<typename T>
        GLB_INLINE constexpr dQuat<T> Conjugate(const dQuat<T>& dq) noexcept
        {
            return dQuat<T>(
                Qua::Conjugate(dq.real),
                Qua::Conjugate(dq.dual)
            );
        }

        template<typename T>
        GLB_INLINE constexpr dQuat<T> Inverse(const dQuat<T>& dq) noexcept
        {
            // const quat<T> invReal = Qua::inverse(dq.real);

            // return dQuat<T>(
            //     invReal,
            //     invReal * dq.dual * invReal
            // );

            const T l2 = Qua::LengthSquared(dq.real);
            const T l4 = l2 * l2;

            const quat<T> conjReal = Qua::Conjugate(dq.real);

            return dQuat<T>(
                conjReal / l2,
                -((conjReal * dq.dual * conjReal) / l4)
            );
        }



        template<typename T>
        GLB_INLINE constexpr quat<T> GetRotation(const dQuat<T>& dq) noexcept
        {
            return dq.real;
        }
        
        template<typename T>
        GLB_INLINE constexpr vec<3, T> GetTranslation(const dQuat<T>& dq) noexcept
        {
            quat<T> trsl = static_cast<T>(2) * (dq.dual * Qua::Conjugate(dq.real));
            return vec<3, T>(trsl.x, trsl.y, trsl.z);
        }

    } // namespace DQua
    
} // namespace glb
