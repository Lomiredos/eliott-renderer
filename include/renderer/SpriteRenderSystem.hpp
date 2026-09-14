#pragma once

#include "renderer/RenderSystem.hpp"
#include "renderer/SpriteBatch.hpp"

namespace ee::renderer
{
    class SpriteRenderSystem : public RenderSystem
    {
    private:
        SpriteBatch m_batch;

    public:
        void render(ee::ecs::World &_world, Renderer &_renderer, Camera &_camera) override;
    };
}
