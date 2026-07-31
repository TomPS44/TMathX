namespace glb
{
    namespace Mat
    {

        template<typename T>
        GLB_INLINE constexpr mat<3, 3, T> Scale_3x3(const vec<3, T>& scale) noexcept
        {
            return mat<3, 3, T>(
                scale
            );
        }
        template<typename T>
        GLB_INLINE constexpr mat<4, 4, T> Scale_4x4(const vec<3, T>& scale) noexcept
        {
            return mat<4, 4, T>(
                vec<4, T>(
                    scale, static_cast<T>(1)
                )
            );
        }

    } // namespace Mat


} // namespace glb
