#pragma once

struct TTF_Font;

namespace ee::renderer
{
    // Wrap RAII d'une police TrueType (SDL3_ttf).
    class Font
    {
    private:
        TTF_Font *m_font = nullptr;

    public:
        Font(const char *_path, float _ptSize);
        ~Font();

        Font(const Font &) = delete;
        Font &operator=(const Font &) = delete;

        TTF_Font *get() const { return m_font; }
    };
}
