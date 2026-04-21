#pragma once
#include "tmx/internal/definitions.hpp"

namespace tmx
{
    // -- Unary operators ---

    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& v) noexcept; 
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& v) noexcept; 

    // --- Arithmetic operators ---
    
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator+(const mat<R, C, T>& v, T scalar) noexcept;

    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator-(const mat<R, C, T>& v, T scalar) noexcept;

    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator*(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator*(const mat<R, C, T>& v, T scalar) noexcept;
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator*(T scalar, const mat<R, C, T>& v) noexcept;

    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr typename mat<R, C, T>::colType operator*(const mat<R, C, T>& m, const typename mat<R, C, T>::colType& v) noexcept;

    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr mat<R, C, T> operator/(const mat<R, C, T>& v, T scalar) noexcept;

   


    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr bool operator==(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
    template<size_t R, size_t C, typename T>
    TMX_INLINE constexpr bool operator!=(const mat<R, C, T>& a, const mat<R, C, T>& b) noexcept;
}

#include "tmx/internal/type_mat.inl"