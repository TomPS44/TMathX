#pragma once

#include "../internal/type-quat.h"
#include "../internal/type-vec.h"

namespace glb
{
    
    namespace Qua
    {
        /// @brief Generates a Quaternion from an axis and an angle 
        /// @param u A unit vector3 deciding which axis to rotate around : `(1, 0, 0)` for `X`, `(0, 1, 0)` for `Y`, `(0, 0, 1)` for `Z`
        /// @param angle The angle to rotate by, in `radians`
        template<typename T>
        GLB_INLINE constexpr quat<T> FromAxisAngle(const vec<3, T>& u, T angle) noexcept;


        /**
         * @brief Generates a Quaternion from a vector `angles` containing the three angles `x`, `y` and `z`, in `radians`.
         * 
         * @attention The order of rotations applied is the one specified by GLB_SET_ROTATION_ORDER_...
         * 
         * If you want to generate a Quaternion with a different rotation order, use glbDetail::FromEuler_...
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> FromEuler(const vec<3, T>& angles) noexcept;
        /**
         * @brief Generates a Quaternion from the three angles `x`, `y` and `z`, in `radians`.
         * 
         * @attention The order of rotations applied is the one specified by GLB_SET_ROTATION_ORDER_...
         * 
         * If you want to generate a Quaternion with a different rotation order, use `glbDetail::FromEuler_...`
         */
        template<typename T>
        GLB_INLINE constexpr quat<T> FromEuler(T x, T y, T z) noexcept;
        /**
         * @brief Returns a vector3 containing the 3 angles, in `radians`,
         * of the rotations around the X, Y and Z axis (respectively in the Vector).
         * 
         * @attention This functions gets the angles from a Quaternion whose rotation order is the one specified by GLB_SET_ROTATION_ORDER_...
         * 
         * If you want to get the rotation angles 
         */
        template<typename T>
        GLB_INLINE constexpr vec<3, T> ToEuler(const quat<T>& q) noexcept;
    }

    namespace glbDetail
    {
        /** @brief Generates a Quaternion from three angles x, y and z in `radians`, respectively contained in the vector `angles`. 
         * 
         * @attention
         * The applied rotation order is XYZ.
        */
        template<typename T>
        GLB_INLINE constexpr quat<T> FromEuler_XYZ(const vec<3, T>& angles) noexcept;

        /** @brief Generates a Quaternion from three angles x, y and z in `radians`, respectively contained in the vector `angles`. 
         * 
         * @attention
         * The applied rotation order is XZY.
        */
        template<typename T>
        GLB_INLINE constexpr quat<T> FromEuler_XZY(const vec<3, T>& angles) noexcept;

        /** @brief Generates a Quaternion from three angles x, y and z in `radians`, respectively contained in the vector `angles`. 
         * 
         * @attention
         * The applied rotation order is YXZ.
        */
        template<typename T>
        GLB_INLINE constexpr quat<T> FromEuler_YXZ(const vec<3, T>& angles) noexcept;

        /** @brief Generates a Quaternion from three angles x, y and z in `radians`, respectively contained in the vector `angles`. 
         * 
         * @attention
         * The applied rotation order is YZX.
        */
        template<typename T>
        GLB_INLINE constexpr quat<T> FromEuler_YZX(const vec<3, T>& angles) noexcept;

        /** @brief Generates a Quaternion from three angles x, y and z in `radians`, respectively contained in the vector `angles`. 
         * 
         * @attention
         * The applied rotation order is ZXY.
        */
        template<typename T>
        GLB_INLINE constexpr quat<T> FromEuler_ZXY(const vec<3, T>& angles) noexcept;

        /** @brief Generates a Quaternion from three angles x, y and z in `radians`, respectively contained in the vector `angles`. 
         * 
         * @attention
         * The applied rotation order is ZYX.
        */
        template<typename T>
        GLB_INLINE constexpr quat<T> FromEuler_ZYX(const vec<3, T>& angles) noexcept;



        /**
         * @brief Extracts the 3 angles, in `radians`, of the rotations around the X, Y and Z axis represented by the Quaternion `q`,
         * and respectively puts them in a vector3.
         * 
         * @attention
         * The rotation order used to extract the angles is XYZ.
         */
        template<typename T>
        GLB_INLINE constexpr vec<3, T> ToEuler_XYZ(const quat<T>& q) noexcept;

        /**
         * @brief Extracts the 3 angles, in `radians`, of the rotations around the X, Y and Z axis represented by the Quaternion `q`,
         * and respectively puts them in a vector3.
         * 
         * @attention
         * The rotation order used to extract the angles is XZY.
         */
        template<typename T>
        GLB_INLINE constexpr vec<3, T> ToEuler_XZY(const quat<T>& q) noexcept;

        /**
         * @brief Extracts the 3 angles, in `radians`, of the rotations around the X, Y and Z axis represented by the Quaternion `q`,
         * and respectively puts them in a vector3.
         * 
         * @attention
         * The rotation order used to extract the angles is YXZ.
         */
        template<typename T>
        GLB_INLINE constexpr vec<3, T> ToEuler_YXZ(const quat<T>& q) noexcept;

        /**
         * @brief Extracts the 3 angles, in `radians`, of the rotations around the X, Y and Z axis represented by the Quaternion `q`,
         * and respectively puts them in a vector3.
         * 
         * @attention
         * The rotation order used to extract the angles is YZX.
         */
        template<typename T>
        GLB_INLINE constexpr vec<3, T> ToEuler_YZX(const quat<T>& q) noexcept;

        /**
         * @brief Extracts the 3 angles, in `radians`, of the rotations around the X, Y and Z axis represented by the Quaternion `q`,
         * and respectively puts them in a vector3.
         * 
         * @attention
         * The rotation order used to extract the angles is ZXY.
         */
        template<typename T>
        GLB_INLINE constexpr vec<3, T> ToEuler_ZXY(const quat<T>& q) noexcept;
        
        /**
         * @brief Extracts the 3 angles, in `radians`, of the rotations around the X, Y and Z axis represented by the Quaternion `q`,
         * and respectively puts them in a vector3.
         * 
         * @attention
         * The rotation order used to extract the angles is ZYX.
         */
        template<typename T>
        GLB_INLINE constexpr vec<3, T> ToEuler_ZYX(const quat<T>& q) noexcept;

    } // namespace Detail

} // namespace glb

#include "../internal/quat/compute-euler.inl"