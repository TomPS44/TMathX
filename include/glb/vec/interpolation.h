#pragma once

#include "../internal/type-vec.h"

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> LerpUnclamped(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Lerp(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> SlerpUnclamped(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> Slerp(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;

        
        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> SmoothDamp(const vec<S, T>& current, const vec<S, T>& target, vec<S, T>& currentVelocity,
                                                  T smoothTime, T deltaTime, T maxSpeed = std::numeric_limits<T>::infinity()) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr vec<S, T> MoveTowards(const vec<S, T>& current, const vec<S, T>& target, T maxDistanceDelta) noexcept;

    } // namespace Vec
} // namespace glb

#include "../internal/vec/compute-interpolation.inl"
