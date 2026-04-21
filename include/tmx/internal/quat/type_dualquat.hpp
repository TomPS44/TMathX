#pragma once

#include "tmx/internal/definitions"
#include "tmx/internal/quat/type_quat.hpp"

namespace tmx
{
    template<typename T>
    struct dualQuat
    {
    public:
        
        union
        {
            quat<T> real, dual;
            quat<T> values[2];
        }
        

        TMX_INLINE constexpr dualQuat() noexcept;
        TMX_INLINE constexpr dualQuat(const dualQuat<T>& dq) noexcept;
        TMX_INLINE constexpr dualQuat(const quat<T>& rot, const vec<3, T>& trsl);
        TMX_INLINE constexpr dualQuat(const quat<T>& rot, const quat<T>& trsl);
        TMX_INLINE constexpr dualQuat(const quat<T>& rot);
        TMX_INLINE constexpr dualQuat(const vec<S, T>& trsl);


        TMX_INLINE constexpr quat<T>& operator[](size_t i);
        TMX_INLINE constexpr const quat<T> operator[](size_t i) const;

        TMX_INLINE constexpr dualQuat<T>& operator=(const dualQuat<T>& dq) = default;


        TMX_INLINE constexpr dualQuat<T>& operator+=(const dualQuat<T>& dq) noexcept;
        TMX_INLINE constexpr dualQuat<T>& operator-=(const dualQuat<T>& dq) noexcept;
        
        TMX_INLINE constexpr dualQuat<T>& operator*=(const dualQuat<T>& dq) noexcept;
        TMX_INLINE constexpr dualQuat<T>& operator*=(T scalar) noexcept;

        TMX_INLINE constexpr dualQuat<T>& operator/=(T scalar) noexcept;
    };

    TMX_INLINE constexpr dualQuat<T> operator+(const dualQuat<T>& dq) noexcept;
    TMX_INLINE constexpr dualQuat<T> operator-(const dualQuat<T>& dq) noexcept;
    
    TMX_INLINE constexpr dualQuat<T> operator+(const dualQuat<T>& a, const dualQuat<T>& b) noexcept;
    TMX_INLINE constexpr dualQuat<T> operator-(const dualQuat<T>& a, const dualQuat<T>& b) noexcept;
    
    TMX_INLINE constexpr dualQuat<T> operator*(const dualQuat<T>& a, const dualQuat<T>& b) noexcept;
    TMX_INLINE constexpr dualQuat<T> operator*(const dualQuat<T>& dq, T scalar) noexcept;
    TMX_INLINE constexpr dualQuat<T> operator*(T scalar, const dualQuat<T>& dq) noexcept;
    TMX_INLINE constexpr vec<3, T> operator*(const dualQuat<T>& dq, const  vec<3, T>& point) noexcept;

    TMX_INLINE constexpr dualQuat<T> operator/(const dualQuat<T>& dq, T scalar) noexcept;
} // namespace tmx
