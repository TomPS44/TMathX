namespace glb
{
    namespace Mat
    {
        template<typename T>
        GLB_INLINE constexpr mat<4, 4, T> Translate(const vec<3, T>& trsl) noexcept
        {
            mat<4, 4, T> res;

            res[3] = vec<4, T>(trsl, static_cast<T>(1));

            return res;
        }

    } // namespace Mat
    
} // namespace glb
