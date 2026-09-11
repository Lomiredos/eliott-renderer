#pragma once

#include <memory>
#include <optional>
#include <cstdint>

#include "renderer/Texture.hpp"
#include "renderer/Color.hpp"
#include "math/Rect.hpp"

namespace ee::renderer
{

    struct Sprite
    {
        std::shared_ptr<Texture> texture;         
        std::optional<ee::math::Rect<float>> srcRect;  
        std::uint8_t alpha = 255;                      
        Color tint = {};                              
        int layer = 0;                               
    };

}
