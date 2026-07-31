#pragma once
#include "definitions.h"

namespace glb
{
    // -- Unary operators ---

    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& v) noexcept; 
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& v) noexcept; 

    // --- Arithmetic operators ---
    
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& v, T scalar) noexcept;

    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& v, T scalar) noexcept;

    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator*(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator*(const mat<R, C, T>& v, T scalar) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator*(T scalar, const mat<R, C, T>& v) noexcept;

    template<int R, int C, typename T>
    GLB_INLINE constexpr typename mat<R, C, T>::colType operator*(const mat<R, C, T>& m, const typename mat<R, C, T>::colType& v) noexcept;

    template<int R, int C, typename T>
    GLB_INLINE constexpr mat<R, C, T> operator/(const mat<R, C, T>& v, T scalar) noexcept;

   


    template<int R, int C, typename T>
    GLB_INLINE constexpr bool operator==(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr bool operator!=(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
}

#include "type-mat.inl"