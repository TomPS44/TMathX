/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




 
#include <cmath>
#include "../type-vec.h"
#include "glb/vec/geometric.h"
#include "glb/quat/exponential.h"
#include "glb/quat/geometric.h"

namespace glb
{
    namespace DQua
    {
        template<typename T>
        GLB_INLINE constexpr dQuat<T> Log(const dQuat<T>& dq) noexcept
        {
            dQuat<T> copy = dq;

            if (copy.real.w < static_cast<T>(0))
            {
                copy = -copy;
            }

            return dQuat<T>(
                Qua::Log(copy.real),
                (copy.dual * Qua::Conjugate(copy.real)) /** static_cast<T>(2.0)*/
            );
        }

        template<typename T>
        GLB_INLINE constexpr dQuat<T> Exp(const dQuat<T>& dq) noexcept
        {
            const vec<3, T> v(dq.real.x, dq.real.y, dq.real.z);
            const vec<3, T> t(dq.dual.x, dq.dual.y, dq.dual.z);
            const T theta = Vec::Length(v);

            if (theta < static_cast<T>(8.0e-05))
            {
                return dQuat<T>(
                    quat<T>(static_cast<T>(1), v),
                    quat<T>(static_cast<T>(0), t)
                );
            }


            const quat<T> expReal = Qua::Exp(dq.real);

            return dQuat<T>(
                expReal,
                (dq.dual * expReal) /** static_cast<T>(0.5)*/
            );

        }


        template<typename T>
        GLB_INLINE constexpr dQuat<T> Pow(const dQuat<T>& dq, T exp) noexcept
        {            
            return DQua::Exp(exp * DQua::Log(dq));
        }
        template<typename T>
        GLB_INLINE constexpr dQuat<T> Sqrt(const dQuat<T>& dq) noexcept
        {
            // n^s = e^(s * ln(n))

            return DQua::Pow(dq, static_cast<T>(0.5));
        }


    } // namespace Qua
} // namespace glb
