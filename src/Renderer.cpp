#include "renderer/Renderer.hpp"
#include "renderer/Texture.hpp"
#include "renderer/SpriteBatch.hpp"
#include "SDL3/SDL.h"

ee::renderer::Renderer::Renderer(float _width, float _height, const char *_name) : m_name(_name), m_width(_width), m_height(_height)
{
    m_window = SDL_CreateWindow(m_name.c_str(), m_width, m_height, 0);

    if (!m_window)
        throw std::runtime_error(SDL_GetError());

    m_renderer = SDL_CreateRenderer(m_window, nullptr);

    if (!m_renderer)
        throw std::runtime_error(SDL_GetError());

    m_textureManager.init(m_renderer);
}

ee::renderer::Renderer::~Renderer()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
}
void ee::renderer::Renderer::Start()
{
    SDL_RenderClear(m_renderer);
}

void ee::renderer::Renderer::End()
{
    SDL_RenderPresent(m_renderer);
}

void ee::renderer::Renderer::Draw(const Texture &_texture,
                                  ee::math::Rect<float> _destRect,
                                  std::optional<ee::math::Rect<float>> _srcRect,
                                  float _angle,
                                  std::uint8_t _alpha,
                                  Color _tint)
{
    // Rectangle de destination : (x, y) = coin haut-gauche pour SDL.
    SDL_FRect dstRect;
    dstRect.x = _destRect.getPosition(0, 0).x;
    dstRect.y = _destRect.getPosition(0, 0).y;
    dstRect.w = _destRect.getSize().x;
    dstRect.h = _destRect.getSize().y;

    // Etat par-instance : on le pose sur la texture (partagee) juste avant
    // de dessiner, a partir des valeurs de CE sprite. Le sprite suivant qui
    // partage la meme texture reecrira ces mods avec les siens -> pas de fuite.
    SDL_SetTextureAlphaMod(_texture.getTexture(), _alpha);
    SDL_SetTextureColorMod(_texture.getTexture(), _tint.r, _tint.g, _tint.b);

    // srcRect optionnel : nullptr => toute la texture.
    SDL_FRect srcRect;
    const SDL_FRect *srcPtr = nullptr;
    if (_srcRect)
    {
        srcRect.x = _srcRect->getPosition(0, 0).x;
        srcRect.y = _srcRect->getPosition(0, 0).y;
        srcRect.w = _srcRect->getSize().x;
        srcRect.h = _srcRect->getSize().y;
        srcPtr = &srcRect;
    }

    // center = nullptr => rotation autour du centre du dstRect.
    SDL_RenderTextureRotated(m_renderer, _texture.getTexture(), srcPtr, &dstRect,
                             _angle, nullptr, SDL_FLIP_NONE);
}
