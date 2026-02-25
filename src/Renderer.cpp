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

void ee::renderer::Renderer::Draw(const Texture &_text, ee::math::Rect<float> _destRect)
{
    SDL_FRect dstRect;
    dstRect.x = _destRect.getPosition(0, 0).x;
    dstRect.y = _destRect.getPosition(0, 0).y;
    dstRect.w = _destRect.getSize().x;
    dstRect.h = _destRect.getSize().y;
    SDL_RenderTexture(m_renderer, _text.getTexture(), nullptr, &dstRect);
}

void ee::renderer::Renderer::Draw(const Texture &_text, ee::math::Rect<float> _destRect, ee::math::Rect<float> _srcRect)
{
        SDL_FRect dstRect;
    dstRect.x = _destRect.getPosition().x;
    dstRect.x = _destRect.getPosition().x;
    dstRect.w = _destRect.getSize().x;
    dstRect.h = _destRect.getSize().y;

        SDL_FRect srcRect;
    srcRect.x = _srcRect.getPosition().x;
    srcRect.x = _srcRect.getPosition().x;
    srcRect.w = _srcRect.getSize().x;
    srcRect.h = _srcRect.getSize().y;
    SDL_RenderTexture(m_renderer, _text.getTexture(), &srcRect, &dstRect);
}
