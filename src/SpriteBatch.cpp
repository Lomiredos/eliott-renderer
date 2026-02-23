#include "renderer/SpriteBatch.hpp"

void ee::renderer::SpriteBatch::DrawAll(Renderer &_rend, const Camera &_cam, const std::vector<SpriteEntry> &_entities)
{
    for (const SpriteEntry &entity : _entities)
    {

        SDL_FRect screenRect = entity.m_destRect;
        screenRect.x = _cam.getScreenX(screenRect.x);
        screenRect.y = _cam.getScreenY(screenRect.y);

        if (entity.m_srcRect)
            _rend.Draw(*entity.m_texture, screenRect, *entity.m_srcRect);

        else
            _rend.Draw(*entity.m_texture, screenRect);
    }
}