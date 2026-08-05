#pragma once

#include "../definitions.h"
#include "../type-mat.h"

namespace glb
{
    template<typename T>
    struct GLB_ALIGN_(T) mat<2, 2, T>
    {
        typedef vec<2, T> colType;
        typedef vec<2, T> rowType;
        typedef mat<2, 2, T> transposeType;

    public:
        
        union 
        {
            colType columns[2];
            T indices[4];
        };


        /**
         * @brief The first row of parameters (x0, y0) is the first column, same thing for the second row.
         */
        GLB_INLINE explicit constexpr mat(T x0, T y0, 
                                 T x1, T y1) noexcept;
        /**
         * @brief Sets the 2 values in the column to `scalar`, and the rest to 0.
         */
        GLB_INLINE explicit constexpr mat(T scalar = static_cast<T>(1.0)) noexcept;
        /**
         * @brief Sets the values in the column to `diag`.
         */
        GLB_INLINE explicit constexpr mat(const colType& diag) noexcept;
        /**
         * @brief Sets the first column to `col1`, and the second column to `col2`.
         */
        GLB_INLINE explicit constexpr mat(const colType& col1, const colType& col2) noexcept;
        /**
         * @brief Copy constructor.
         */
        GLB_INLINE constexpr mat(const mat<2, 2, T>& m) noexcept;
        /**
         * @brief Sets the matrix values to the top 2x2 matrix of `m`.
         */
        GLB_INLINE explicit constexpr mat(const mat<3, 3, T>& m) noexcept;
        /**
         * @brief Sets the matrix values to the top 2x2 matrix of `m`.
         */
        GLB_INLINE explicit constexpr mat(const mat<4, 4, T>& m) noexcept;


        /**
         * Returns a const pointer to the first element (mat[0][0]) of the matrix.
         */
        GLB_INLINE constexpr const T* data() const noexcept { return &(columns[0].x); };

        GLB_INLINE constexpr const vec<2, T> GetRow(int index) { return vec<2, T>(columns[0][index], columns[1][index]); }; 
        GLB_INLINE constexpr void SetRow(int index, const vec<2, T>& v) { columns[0][index] = v.x; columns[1][index] = v.y; }; 

        GLB_INLINE constexpr explicit operator mat<3, 3, T>() const noexcept { return mat<3, 3, T>(*this); };
        GLB_INLINE constexpr explicit operator mat<4, 4, T>() const noexcept { return mat<4, 4, T>(*this); };


        GLB_INLINE constexpr colType& operator[](int i);
        GLB_INLINE constexpr const colType& operator[](int i) const;


        GLB_INLINE constexpr mat<2, 2, T>& operator=(const mat<2, 2, T>& m) noexcept = default;

        GLB_INLINE constexpr mat<2, 2, T>& operator+=(const mat<2, 2, T>& m) noexcept;
        GLB_INLINE constexpr mat<2, 2, T>& operator+=(T scalar) noexcept;

        GLB_INLINE constexpr mat<2, 2, T>& operator-=(const mat<2, 2, T>& m) noexcept;
        GLB_INLINE constexpr mat<2, 2, T>& operator-=(T scalar) noexcept;

        GLB_INLINE constexpr mat<2, 2, T>& operator*=(const mat<2, 2, T>& m) noexcept;
        GLB_INLINE constexpr mat<2, 2, T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr mat<2, 2, T>& operator/=(T scalar) noexcept;
    };
}

#include "type-mat2x2.inl"