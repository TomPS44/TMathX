namespace tmx
{
    // --- Constructors ---

    template<typename T>
    TMX_INLINE constexpr dualQuat<T>::dualQuat() noexcept
    : real(quat<T>()), dual(quat<T>(0, 0, 0, 0))
    {}

    template<typename T>
    TMX_INLINE constexpr dualQuat<T>::dualQuat(const quat<T>& rot, const vec<3, T>& trsl)  noexcept
    : real(rot), dual(0.5 * (quat<T>(0, trsl)) * rot)
    {}

    template<typename T>
    TMX_INLINE constexpr dualQuat<T>::dualQuat(const quat<T>& rot, const quat<T>& trsl) noexcept
    : real(rot), dual(trsl)
    {}

    template<typename T>
    TMX_INLINE constexpr dualQuat<T>::dualQuat(const quat<T>& rot) noexcept
    : real(rot), dual(quat<T>(0, 0, 0, 0))
    {}

    template<typename T>
    TMX_INLINE constexpr dualQuat<T>::dualQuat(const vec<3, T>& trsl) noexcept
    : real(rot), dual(quat<T>(0, trsl * 0.5))
    {}


    // --- Accessors ---


    template<typename T>
    TMX_INLINE constexpr quat<T>& dualQuat<T>







    DualQuat
    DQuat
}