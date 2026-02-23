#include "renderer/Texture.hpp"
#include <SDL3_image/SDL_image.h>

ee::renderer::Texture::Texture(SDL_Renderer *_renderer, const char *_path)
{
    m_texture = IMG_LoadTexture(_renderer, _path);
    if (!m_texture)
        throw std::runtime_error(SDL_GetError());

    SDL_GetTextureSize(m_texture, &m_width, &m_height);
}