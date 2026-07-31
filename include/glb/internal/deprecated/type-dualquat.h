/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




#pragma once

#include "../definitions.h"
#include "../type-quat.h"

namespace glb
{
    /**
     * DO NOT USE THIS TYPE, IT'S STILL IN DEVELOPMENT !!!
     */
    template<typename T>
    struct dQuat
    {
    public:
        
        quat<T> real, dual;
        

        GLB_INLINE constexpr dQuat() noexcept;
        GLB_INLINE constexpr dQuat(const dQuat<T>& dq) noexcept;
        GLB_INLINE constexpr dQuat(const quat<T>& rot, const vec<3, T>& trsl) noexcept;
        GLB_INLINE constexpr dQuat(const quat<T>& rot, const quat<T>& trsl) noexcept;
        GLB_INLINE constexpr dQuat(const quat<T>& rot) noexcept;
        GLB_INLINE constexpr dQuat(const vec<3, T>& trsl) noexcept;


        GLB_INLINE constexpr quat<T>& operator[](int i);
        GLB_INLINE constexpr const quat<T>& operator[](int i) const;

        GLB_INLINE constexpr dQuat<T>& operator=(const dQuat<T>& dq) = default;


        GLB_INLINE constexpr dQuat<T>& operator+=(const dQuat<T>& dq) noexcept;
        GLB_INLINE constexpr dQuat<T>& operator-=(const dQuat<T>& dq) noexcept;
        
        GLB_INLINE constexpr dQuat<T>& operator*=(const dQuat<T>& dq) noexcept;
        GLB_INLINE constexpr dQuat<T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr dQuat<T>& operator/=(T scalar) noexcept;
    };

    template<typename T>
    GLB_INLINE constexpr dQuat<T> operator+(const dQuat<T>& dq) noexcept;
    template<typename T>
    GLB_INLINE constexpr dQuat<T> operator-(const dQuat<T>& dq) noexcept;

    template<typename T>
    GLB_INLINE constexpr dQuat<T> operator+(const dQuat<T>& a, const dQuat<T>& b) noexcept;
    template<typename T>
    GLB_INLINE constexpr dQuat<T> operator-(const dQuat<T>& a, const dQuat<T>& b) noexcept;

    template<typename T>
    GLB_INLINE constexpr dQuat<T> operator*(const dQuat<T>& a, const dQuat<T>& b) noexcept;
    template<typename T>
    GLB_INLINE constexpr dQuat<T> operator*(const dQuat<T>& dq, T scalar) noexcept;
    template<typename T>
    GLB_INLINE constexpr dQuat<T> operator*(T scalar, const dQuat<T>& dq) noexcept;
    template<typename T>
    GLB_INLINE constexpr vec<3, T> operator*(const dQuat<T>& dq, const vec<3, T>& point) noexcept;

    template<typename T>
    GLB_INLINE constexpr dQuat<T> operator/(const dQuat<T>& dq, T scalar) noexcept;


    template<typename T>
    GLB_INLINE constexpr bool operator==(const dQuat<T>& a, const dQuat<T>& b) noexcept;
    template<typename T>
    GLB_INLINE constexpr bool operator!=(const dQuat<T>& a, const dQuat<T>& b) noexcept;
} // namespace glb

#include "type-dualquat.inl"
