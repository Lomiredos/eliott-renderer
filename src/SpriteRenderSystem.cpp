#include "renderer/SpriteRenderSystem.hpp"
#include "renderer/Sprite.hpp"
#include "ecs/World.hpp"
#include "math/Transform.hpp"

#include <vector>
#include <algorithm>

void ee::renderer::SpriteRenderSystem::render(ee::ecs::World &_world, Renderer &_renderer, Camera &_camera)
{
    std::vector<ee::ecs::EntityID> ordered(m_entities.begin(), m_entities.end());

    std::sort(ordered.begin(), ordered.end(),
              [&_world](ee::ecs::EntityID _a, ee::ecs::EntityID _b)
              {
                  return _world.getComponent<Sprite>(_a)->layer <
                         _world.getComponent<Sprite>(_b)->layer;
              });

    std::vector<SpriteEntry> entries;
    entries.reserve(ordered.size());

    for (ee::ecs::EntityID id : ordered)
    {
        ee::math::Transform *transform = _world.getComponent<ee::math::Transform>(id);
        Sprite *sprite = _world.getComponent<Sprite>(id);

        if (transform == nullptr || sprite == nullptr || !sprite->texture)
            continue;

        ee::math::Vector2<float> baseSize =
            sprite->srcRect
                ? sprite->srcRect->getSize()
                : ee::math::Vector2<float>(sprite->texture->getWidth(), sprite->texture->getHeight());

        ee::math::Vector2<float> drawSize(baseSize.x * transform->scale.x,
                                          baseSize.y * transform->scale.y);

        ee::math::Rect<float> destRect;
        destRect.setSize(drawSize);
        destRect.setPosition(transform->position);

        SpriteEntry entry;
        entry.m_texture = sprite->texture.get();
        entry.m_destRect = destRect;
        entry.m_srcRect = sprite->srcRect;
        entry.m_angle = transform->rotation;
        entry.m_alpha = sprite->alpha;
        entry.m_tint = sprite->tint;

        entries.push_back(entry);
    }

    m_batch.DrawAll(_renderer, _camera, entries);
}
