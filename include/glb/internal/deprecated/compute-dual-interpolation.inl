/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




 

#include "dual-geometric.h"
#include "dual-exponential.h"
#include "glb/quat/geometric.h"

namespace glb
{
    
    namespace DQua
    {    
        template<typename T>
        GLB_INLINE constexpr dQuat<T> Lerp(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return DQua::LerpUnclamped(start, end, t);
        }
        template<typename T>
        GLB_INLINE constexpr dQuat<T> LerpUnclamped(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept
        {
            dQuat<T> e = end;

            if (Qua::Dot(start.real, e.real) < static_cast<T>(0))
            {
                e = -e;
            }

            return DQua::Normalize( (static_cast<T>(1) - t) * start + e * t );
        }

        template<typename T>
        GLB_INLINE constexpr dQuat<T> Slerp(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            // return Qua::slerpUnclamped(start, end, t);
            return DQua::SlerpUnclamped(start, end, t);
        }
        template<typename T>
        GLB_INLINE constexpr dQuat<T> SlerpUnclamped(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept
        {
            return DQua::Normalize( start * DQua::Pow(DQua::Inverse(start) * end, t) );

            // return glbInternal::quatSlerpUnclamped<T, glbInternal::useSimd<4, T>::value>::call(start, end, t);
        }

    } // namespace Qua

} // namespace glb