#include "renderer/Texture.hpp"
#include "SDL3/SDL.h"
#include <SDL3_image/SDL_image.h>

ee::renderer::Texture::Texture(SDL_Renderer *_renderer, const char *_path)
{
    m_texture = IMG_LoadTexture(_renderer, _path);
    if (!m_texture)
        throw std::runtime_error(SDL_GetError());

    // Necessaire pour que l'alpha mod (transparence reglable) soit visible.
    SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);

    SDL_GetTextureSize(m_texture, &m_width, &m_height);
}
ee::renderer::Texture::~Texture()
{
    SDL_DestroyTexture(m_texture);
};