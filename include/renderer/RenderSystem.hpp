#pragma once

#include "ecs/System.hpp"

namespace ee::ecs { class World; }

namespace ee::renderer
{
    class Renderer;
    class Camera;

    // Systeme de rendu : appele automatiquement par la Scene pendant draw().
    class RenderSystem : public ee::ecs::System
    {
    public:
        virtual void render(ee::ecs::World &_world, Renderer &_renderer, Camera &_camera) = 0;
    };
}
