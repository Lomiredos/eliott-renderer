#pragma once

#include <vector>
#include <optional>
#include <cstdint>

#include "Texture.hpp"
#include "Renderer.hpp"
#include "Camera.hpp"
#include "Color.hpp"

#include "math/Rect.hpp"

namespace ee::renderer
{

    struct SpriteEntry
    {
        const Texture *m_texture;
        ee::math::Rect<float> m_destRect;
        std::optional<ee::math::Rect<float>> m_srcRect;

        float m_angle = 0.0f;        
        std::uint8_t m_alpha = 255;  
        Color m_tint = {};           
    };

    class SpriteBatch
    {

    public:
        void DrawAll(Renderer &_rend, const Camera &_cam, const std::vector<SpriteEntry> &_entities);
    };

}