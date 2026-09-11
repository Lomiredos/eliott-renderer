#pragma once

#include <cstdint>

namespace ee::renderer
{

    // Couleur RGB pour la teinte (color modulation).
    // Defaut = blanc (255,255,255) => aucune teinte (multiplication par 1).
    struct Color
    {
        std::uint8_t r = 255;
        std::uint8_t g = 255;
        std::uint8_t b = 255;
    };

}
