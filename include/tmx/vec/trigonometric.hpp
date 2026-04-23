#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vector
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> toRad(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> toDeg(const vec<S, T>& v) noexcept;


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> sin(const vec<S, T>& v) noexcept;
    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> cos(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> tan(const vec<S, T>& v) noexcept;

    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> asin(const vec<S, T>& v) noexcept;
        
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> acos(const vec<S, T>& v) noexcept;
    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> atan(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> atan2(const vec<S, T>& a, const vec<S, T>& b) noexcept;


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> sinh(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> cosh(const vec<S, T>& v) noexcept;
    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> tanh(const vec<S, T>& v) noexcept;


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> asinh(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> acosh(const vec<S, T>& v) noexcept;
    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> atanh(const vec<S, T>& v) noexcept;
        
        
    } // namespace Vector
}

#include "tmx/internal/vec/compute_trigonometric.inl"