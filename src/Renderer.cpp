#include "renderer/Renderer.hpp"
#include "renderer/Texture.hpp"
#include "renderer/SpriteBatch.hpp"

void ee::renderer::Renderer::Start()
{
    SDL_RenderClear(m_renderer);
}

void ee::renderer::Renderer::End()
{
    SDL_RenderPresent(m_renderer);
}

void ee::renderer::Renderer::Draw(const Texture &_text, SDL_FRect _destRect) {
    SDL_RenderTexture(m_renderer, _text.getTexture(), nullptr, &_destRect);
}

void ee::renderer::Renderer::Draw(const Texture &_text, SDL_FRect _destRect, SDL_FRect _srcRect) {
    SDL_RenderTexture(m_renderer, _text.getTexture(), &_srcRect, &_destRect);
}
