#pragma once
#include "tmx/internal/definitions.hpp"

namespace tmx
{
    // -- Unary operators ---

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator+(const vec<S, T>& v) noexcept; 
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator-(const vec<S, T>& v) noexcept; 

    // --- Arithmetic (binary) operators ---
    
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator+(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator+(const vec<S, T>& v, T scalar) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator+(T scalar, const vec<S, T>& v) noexcept;

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator-(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator-(const vec<S, T>& v, T scalar) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator-(T scalar, const vec<S, T>& v) noexcept;

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator*(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator*(const vec<S, T>& v, T scalar) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator*(T scalar, const vec<S, T>& v) noexcept;

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator/(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator/(const vec<S, T>& v, T scalar) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator/(T scalar, const vec<S, T>& v) noexcept;

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator%(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator%(const vec<S, T>& v, T scalar) noexcept;

    // --- Bitwise operators

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator&(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator&(const vec<S, T>& v, T scalar) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator&(T scalar, const vec<S, T>& v) noexcept;

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator|(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator|(const vec<S, T>& v, T scalar) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator|(T scalar, const vec<S, T>& v) noexcept;

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator^(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator^(const vec<S, T>& v, T scalar) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator^(T scalar, const vec<S, T>& v) noexcept;

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator<<(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator<<(const vec<S, T>& v, T scalar) noexcept;

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator>>(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator>>(const vec<S, T>& v, T scalar) noexcept;


    template<size_t S, typename T>
    TMX_INLINE constexpr bool operator==(const vec<S, T>& a, const vec<S, T>& b) noexcept;
    template<size_t S, typename T>
    TMX_INLINE constexpr bool operator!=(const vec<S, T>& a, const vec<S, T>& b) noexcept;

    // --- Unary Bitwise operators

    template<size_t S, typename T>
    TMX_INLINE constexpr vec<S, T> operator~(const vec<S, T>& v) noexcept;



    
}

#include "tmx/internal/type_vec.inl"