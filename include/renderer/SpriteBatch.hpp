#pragma once

#include <vector>
#include <optional>

#include "Texture.hpp"
#include "Renderer.hpp"
#include "Camera.hpp"

#include "math/Rect.hpp"

namespace ee::renderer
{

    struct SpriteEntry
    {
        const Texture *m_texture;
        ee::math::Rect<float> m_destRect;
        std::optional<ee::math::Rect<float>> m_srcRect;
    };

    class SpriteBatch
    {

    public:
        void DrawAll(Renderer &_rend, const Camera &_cam, const std::vector<SpriteEntry> &_entities);
    };

}