#pragma once
#include <string>
#include <memory>
#include <optional>
#include <cstdint>

#include "renderer/Texture.hpp"
#include "renderer/Color.hpp"
#include "math/Rect.hpp"
#include "renderer/TextureManager.hpp"

struct SDL_Window;
struct SDL_Renderer;

namespace ee::renderer
{

    class Font;

    class Renderer
    {

    private:
        SDL_Window *m_window = nullptr;
        SDL_Renderer *m_renderer = nullptr;

        TextureManager m_textureManager;
        std::string m_name;
        float m_width;
        float m_height;

    public:
        Renderer(float _width, float _height, const char *_name);
        ~Renderer();

        std::shared_ptr<Texture> createTexture(std::string _name, const char *_path) 
        {
            return m_textureManager.addTexture(_name, _path);
        }

        std::shared_ptr<Texture> getTexture(std::string _name) 
        {
            return m_textureManager.getTexture(_name);
        }

        void Start();
        void End();

        void Draw(const Texture &_texture,
                  ee::math::Rect<float> _destRect,
                  std::optional<ee::math::Rect<float>> _srcRect = std::nullopt,
                  float _angle = 0.0f,
                  std::uint8_t _alpha = 255,
                  Color _tint = {},
                  bool _flipX = false,
                  bool _flipY = false);

        // Rectangle plein ou en contour (debug, sol, UI simple).
        void DrawRect(ee::math::Rect<float> _rect, Color _color, bool _filled = true);

        // Rend une chaine en texture (a mettre en cache, pas a chaque frame).
        std::shared_ptr<Texture> createText(const std::string &_text, Font &_font, Color _color);
    };
}