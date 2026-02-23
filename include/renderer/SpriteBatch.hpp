#pragma once

#include <vector>
#include <optional>

#include "SDL3/SDL.h"

#include "Texture.hpp"
#include "Renderer.hpp"
#include "Camera.hpp"

namespace ee::renderer
{

    struct SpriteEntry
    {
        const Texture *m_texture;
        SDL_FRect m_destRect;
        std::optional<SDL_FRect> m_srcRect;
    };

    class SpriteBatch
    {

    public:
        void DrawAll(Renderer &_rend, const Camera &_cam, const std::vector<SpriteEntry> &_entities);
    };

}