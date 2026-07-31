#pragma once

#include "definitions.h"

namespace glb
{
    template<typename T>
    struct GLB_ALIGN_(T) quat
    {
    public:
        
        union 
        {
            struct { T w, x, y, z; };
            typename glbInternal::simdReg<4, T>::type reg;
        };

        /**
         * @brief Generates a Quaternion with its `w, x, y, z` components being respectively `qw, qx, qy, qz`, in that order.
         */
        GLB_INLINE explicit constexpr quat(T qw, T qx, T qy, T qz) noexcept;
        /**
         * @brief Generates a Quaternion with `qw` being the real scalar part, and `xyz` the imaginary vector part.
         */
        GLB_INLINE explicit constexpr quat(T qw, const vec<3, T>& xyz) noexcept;
        /**
         * @brief Copy constructor.
         */
        GLB_INLINE constexpr quat(const quat<T>& q) noexcept;
        /**
         * @brief Default constructor, that generates an `identity` Quaternion `(1, (0, 0, 0))`.
         */
        GLB_INLINE explicit constexpr quat() noexcept;


        /**
         * Returns a const pointer to the first element (w) of the Quaternion.
         */
        GLB_INLINE constexpr const T* data() const noexcept { return &w; };


        /**
         * Index accessor.
         * @retval
         * `w` if `i` is `0`,
         * 
         * `x` if i is `1` 
         * `y` if i is `2` 
         * `z` if i is `3` 
         */
        GLB_INLINE constexpr T& operator[](int i);
        /**
         * Index accessor.
         * @retval
         * `w` if `i` is `0`,
         * 
         * `x` if i is `1` 
         * `y` if i is `2` 
         * `z` if i is `3` 
         */
        GLB_INLINE constexpr const T operator[](int i) const;

        /**
         * @brief Returns a vector3 containing the imaginary part of the Quaternion.
         */
        GLB_INLINE constexpr const vec<3, T>& xyz() const { return vec<3, T>(x, y, z); };

        GLB_INLINE constexpr quat<T>& operator=(const quat<T>& q) noexcept = default;


        
        GLB_INLINE constexpr quat<T>& operator+=(const quat<T>& q) noexcept;
        GLB_INLINE constexpr quat<T>& operator-=(const quat<T>& q) noexcept;

        GLB_INLINE constexpr quat<T>& operator*=(T scalar) noexcept;
        GLB_INLINE constexpr quat<T>& operator*=(const quat<T>& q) noexcept;

        GLB_INLINE constexpr quat<T>& operator/=(T scalar) noexcept;
        
    };

    template<typename T>
    GLB_INLINE constexpr quat<T> operator+(const quat<T>& q) noexcept;
    template<typename T>
    GLB_INLINE constexpr quat<T> operator-(const quat<T>& q) noexcept;


    template<typename T>
    GLB_INLINE constexpr quat<T> operator+(const quat<T>& a, const quat<T>& b) noexcept;
    template<typename T>
    GLB_INLINE constexpr quat<T> operator-(const quat<T>& a, const quat<T>& b) noexcept;

    template<typename T>
    GLB_INLINE constexpr quat<T> operator*(const quat<T>& a, const quat<T>& b) noexcept;
    template<typename T>
    GLB_INLINE constexpr quat<T> operator*(const quat<T>& a, T scalar) noexcept;
    template<typename T>
    GLB_INLINE constexpr quat<T> operator*(T scalar, const quat<T>& a) noexcept;
    template<typename T>
    GLB_INLINE constexpr vec<3, T> operator*(const quat<T>& q, const vec<3, T>& v) noexcept;

    template<typename T>
    GLB_INLINE constexpr quat<T> operator/(const quat<T>& q, T scalar) noexcept;
    template<typename T>
    GLB_INLINE constexpr quat<T> operator/(T scalar, const quat<T>& q) noexcept;


    template<typename T>
    GLB_INLINE constexpr bool operator==(const quat<T>& a, const quat<T>& b) noexcept;
    template<typename T>
    GLB_INLINE constexpr bool operator!=(const quat<T>& a, const quat<T>& b) noexcept;
}

#include "type-quat.inl"