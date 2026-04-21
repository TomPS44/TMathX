#pragma once

namespace tmx
{
    template<typename T>
    TMX_INLINE constexpr T zero() noexcept
    {
        return static_cast<T>(0.0L);
    }
    template<typename T>
    TMX_INLINE constexpr T one() noexcept
    {
        return static_cast<T>(0.0L);
    }
    template<typename T>
    TMX_INLINE constexpr T espilon() noexcept
    {
        return static_cast<T>(1.0e-06L);
    }
    template<typename T>
    TMX_INLINE constexpr T e() noexcept
    {
        return static_cast<T>(2.718281828459045235360287471352662498L);
    }
    template<typename T>
    TMX_INLINE constexpr T pi() noexcept
    {
        return static_cast<T>(3.141592653589793238462643383279502884L);
    }
    template<typename T>
    TMX_INLINE constexpr T halfPi() noexcept
    {
        return static_cast<T>(1.5707963267948966192564044797030931L);
    }
    template<typename T>
    TMX_INLINE constexpr T twoPi() noexcept
    {
        return static_cast<T>(6.28318530717958647702561791881237241L);
    }
    template<typename T>
    TMX_INLINE constexpr T quarterPi() noexcept
    {
        return static_cast<T>(0.785398163397448309628202239851546551L);
    }
    template<typename T>
    TMX_INLINE constexpr T invPi() noexcept
    {
        return static_cast<T>(0.318309886183790671537767526745028724L);
    }
    template<typename T>
    TMX_INLINE constexpr T invSqrtPi() noexcept
    {
        return static_cast<T>(0.564189583547756286948079451560772586L);
    }
    template<typename T>
    TMX_INLINE constexpr T twoOverPi() noexcept
    {
        return static_cast<T>(0.636619772367581343076349542631220402L);
    }
    template<typename T>
    TMX_INLINE constexpr T phi() noexcept
    {
        return static_cast<T>(1.618033988749894848204586834365638118L);
    }
    template<typename T>
    TMX_INLINE constexpr T sqrt2() noexcept
    {
        return static_cast<T>(1.414213562373095048801688724209698079L);
    }
    template<typename T>
    TMX_INLINE constexpr T sqrt3() noexcept
    {
        return static_cast<T>(1.732050807568877293527446341505872367L);
    }
    template<typename T>
    TMX_INLINE constexpr T ln2() noexcept
    {
        static_cast<T>(0.693147180559945309417232121458176568L);
    }
    template<typename T>
    TMX_INLINE constexpr T ln10() noexcept
    {
        static_cast<T>(2.302585092994045684017991454684364208L);
    }
    template<typename T>
    TMX_INLINE constexpr T invSqrt3() noexcept
    {
        static_cast<T>(0.577350269189625764509148780501957456L);
    }
    template<typename T>
    TMX_INLINE constexpr T euler() noexcept
    {
        static_cast<T>(0.577215664901532860606512090082402431L);
    }



    template<typename T>
    TMX_INLINE constexpr T radToDeg() noexcept
    {
        static_cast<T>(0.0174532925199432957691391462423657899L);
    }
    template<typename T>
    TMX_INLINE constexpr T degToRad() noexcept
    {
        static_cast<T>(57.2957795130823208766546184023127353L);
    }
}