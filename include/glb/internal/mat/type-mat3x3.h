#pragma once

#include "../definitions.h"
#include "../type-mat.h"

namespace glb
{
    template<typename T>
    struct GLB_ALIGN_(T) mat<3, 3, T>
    {
        typedef vec<3, T> colType;
        typedef vec<3, T> rowType;
        typedef mat<3, 3, T> transposeType;

    public:
        
        union 
        {
            colType columns[3];
            T indices[9];
        };


        GLB_INLINE explicit constexpr mat(T x0, T y0, T z0,
                                 T x1, T y1, T z1,
                                 T x2, T y2, T z2) noexcept;
        GLB_INLINE explicit constexpr mat(T scalar = static_cast<T>(1.0)) noexcept;
        GLB_INLINE explicit constexpr mat(const colType& v1, const colType& v2, const colType& v3) noexcept;
        GLB_INLINE explicit constexpr mat(const colType& diag) noexcept;
        GLB_INLINE explicit constexpr mat(const mat<2, 2, T>& m) noexcept;
        GLB_INLINE constexpr mat(const mat<3, 3, T>& m) noexcept;
        GLB_INLINE explicit constexpr mat(const mat<4, 4, T>& m) noexcept;


        GLB_INLINE constexpr const T* data() const noexcept { return &(columns[0].x); };

        GLB_INLINE constexpr const vec<3, T> GetRow(int index) { return vec<3, T>(columns[0][index], columns[1][index], columns[2][index]); }; 
        GLB_INLINE constexpr void SetRow(int index, const vec<3, T>& v) { columns[0][index] = v.x; columns[1][index] = v.y; columns[2][index] = v.z; }; 




        GLB_INLINE constexpr explicit operator mat<2, 2, T>() const noexcept { return mat<2, 2, T>(*this); };
        GLB_INLINE constexpr explicit operator mat<4, 4, T>() const noexcept { return mat<4, 4, T>(*this); };


        GLB_INLINE constexpr colType& operator[](int i);
        GLB_INLINE constexpr const colType& operator[](int i) const;


        GLB_INLINE constexpr mat<3, 3, T>& operator=(const mat<3, 3, T>& m) noexcept = default;

        GLB_INLINE constexpr mat<3, 3, T>& operator+=(const mat<3, 3, T>& m) noexcept;
        GLB_INLINE constexpr mat<3, 3, T>& operator+=(T scalar) noexcept;

        GLB_INLINE constexpr mat<3, 3, T>& operator-=(const mat<3, 3, T>& m) noexcept;
        GLB_INLINE constexpr mat<3, 3, T>& operator-=(T scalar) noexcept;

        GLB_INLINE constexpr mat<3, 3, T>& operator*=(const mat<3, 3, T>& m) noexcept;
        GLB_INLINE constexpr mat<3, 3, T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr mat<3, 3, T>& operator/=(T scalar) noexcept;
    };
}

#include "type-mat3x3.inl"