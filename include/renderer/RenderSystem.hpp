#pragma once

#include "ecs/System.hpp"

namespace ee::renderer
{
    class RenderSystem : public ee::ecs::System
    {
    public:
        void update(ee::ecs::World &_world, float _dt) override {}
    };
}
