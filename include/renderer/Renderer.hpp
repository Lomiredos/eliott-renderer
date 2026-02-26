#pragma once
#include <string>
#include <memory>

#include "renderer/Texture.hpp"
#include "math/Rect.hpp"
#include "renderer/TextureManager.hpp"

struct SDL_Window;
struct SDL_Renderer;

namespace ee::renderer
{

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

        void Draw(const Texture &_text, ee::math::Rect<float> _destRect);
        void Draw(const Texture &_text, ee::math::Rect<float> _destRect, ee::math::Rect<float> _srcRect);
    };
}