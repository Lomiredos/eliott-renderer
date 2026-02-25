#include "renderer/SpriteBatch.hpp"
#include "SDL3/SDL.h"

void ee::renderer::SpriteBatch::DrawAll(Renderer &_rend, const Camera &_cam, const std::vector<SpriteEntry> &_entities)
{
    for (const SpriteEntry &entity : _entities)
    {

        ee::math::Rect<float> screenRect = entity.m_destRect;

        screenRect.setPosition(ee::math::Vector2<float>(_cam.getScreenX(screenRect.getPosition().x), _cam.getScreenY(screenRect.getPosition().y)));

        if (entity.m_srcRect)
            _rend.Draw(*entity.m_texture, screenRect, *entity.m_srcRect);

        else
        _rend.Draw(*entity.m_texture, screenRect);
    }
}