#pragma once
#include "definitions.h"

namespace glb
{
    // -- Unary operators ---

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator+(const vec<S, T>& v) noexcept; 
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator-(const vec<S, T>& v) noexcept; 

    // --- Arithmetic (binary) operators ---
    
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator+(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator+(const vec<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator+(T scalar, const vec<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator-(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator-(const vec<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator-(T scalar, const vec<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator*(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator*(const vec<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator*(T scalar, const vec<S, T>& v) noexcept;

    /// @brief DO NOT DIVIDE BY ZERO IF T IS AN INTEGRAL TYPE !!!
    /// @tparam T 
    /// @tparam S 
    /// @param a 
    /// @param b 
    /// @return 
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator/(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator/(const vec<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator/(T scalar, const vec<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator%(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator%(const vec<S, T>& v, T scalar) noexcept;

    // --- Bitwise operators

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator&(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator&(const vec<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator&(T scalar, const vec<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator|(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator|(const vec<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator|(T scalar, const vec<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator^(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator^(const vec<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator^(T scalar, const vec<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator<<(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator<<(const vec<S, T>& v, T scalar) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator>>(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator>>(const vec<S, T>& v, T scalar) noexcept;


    template<int S, typename T>
    GLB_INLINE constexpr bool operator==(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr bool operator!=(const vec<S, T>& a, const vec<S, T>& b) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr bool operator<(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr bool operator<=(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr bool operator>(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr bool operator>=(const vec<S, T>& a, const vec<S, T>& b) noexcept;

    // --- Unary Bitwise operators

    template<int S, typename T>
    GLB_INLINE constexpr vec<S, T> operator~(const vec<S, T>& v) noexcept;



    
}

#include "type-vec.inl"