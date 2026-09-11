#pragma once

#include <memory>

#include "ecs/World.hpp"
#include "math/Transform.hpp"

#include "renderer/RenderSystem.hpp"
#include "renderer/Sprite.hpp"
#include "renderer/SpriteBatch.hpp"
#include "renderer/Renderer.hpp"
#include "renderer/Camera.hpp"

namespace ee::renderer
{


    class SpriteRenderer
    {
    private:
        ee::ecs::World &m_world;
        std::shared_ptr<RenderSystem> m_system;
        SpriteBatch m_batch;

    public:
        SpriteRenderer(ee::ecs::World &_world) : m_world(_world)
        {
            m_system = m_world.registerSystem<RenderSystem>();

            ee::ecs::Signature sig;
            sig.set(ee::ecs::getComponentID<ee::math::Transform>());
            sig.set(ee::ecs::getComponentID<ee::renderer::Sprite>());

            m_world.setSystemSignature<RenderSystem>(sig);
        }

        void render(Renderer &_renderer, const Camera &_camera);
    };

}
