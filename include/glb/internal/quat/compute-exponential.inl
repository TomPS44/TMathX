#include <cmath>
#include "glb/internal/type-vec.h"
#include "glb/vec/geometric.h"
#include "glb/quat/geometric.h"

namespace glb
{
    namespace Qua
    {
        template<typename T>
        GLB_INLINE constexpr quat<T> Exp(const quat<T>& q) noexcept
        {
            const vec<3, T> imag(q.x, q.y, q.z);
            const T len = Vec::Length(imag);

            if (len < static_cast<T>(8.0e-05))
            {
                return quat<T>(static_cast<T>(2.718281828459045235360287471352662498L), vec<3, T>{});
            }
            else
            {
                return quat<T>(std::cos(len), (imag / len) * std::sin(len)) * std::exp(q.w);
            }

        }

        
        template<typename T>
        GLB_INLINE constexpr quat<T> Log(const quat<T>& q) noexcept
        {
            const T qLen = Qua::Length(q);
            const vec<3, T> imag(q.x, q.y, q.z);
            const T vLen = Vec::Length(imag);

            if (qLen < static_cast<T>(8.0e-05) || vLen < static_cast<T>(8.0e-05))
            {
                return quat<T>(0, 0, 0, 0);
            }
            else
            {
                const T imagCoef = (static_cast<T>(1) / vLen) * std::acos(q.w / qLen);

                return quat<T>(std::log(qLen), imagCoef * imag);
            }
        }


        template<typename T>
        GLB_INLINE constexpr quat<T> Pow(const quat<T>& q, T exp) noexcept
        {
            return Qua::Exp(exp * Qua::Log(q));
        }
        template<typename T>
        GLB_INLINE constexpr quat<T> Sqrt(const quat<T>& q) noexcept
        {
            return Qua::Pow(q, static_cast<T>(0.5));
        }


        


    } // namespace Qua
} // namespace glb
