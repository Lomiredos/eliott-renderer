#include "renderer/Font.hpp"

#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL.h>
#include <stdexcept>

ee::renderer::Font::Font(const char *_path, float _ptSize)
{
    m_font = TTF_OpenFont(_path, _ptSize);
    if (!m_font)
        throw std::runtime_error(SDL_GetError());
}

ee::renderer::Font::~Font()
{
    if (m_font)
        TTF_CloseFont(m_font);
}
