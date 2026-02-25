#pragma once
#include <string>
#include <memory>

#include "Texture.hpp"
#include "math/Rect.hpp"

struct SDL_Window;
struct SDL_Renderer;

namespace ee::renderer{

    class Renderer{
        
        private:
            SDL_Window* m_window = nullptr;
            SDL_Renderer* m_renderer = nullptr;            
            std::string m_name;
            float m_width;
            float m_height;

        public:

        Renderer( float _width, float _height, const char* _name);
        ~Renderer();


        std::unique_ptr<Texture> createTexture(const char* _path) {return std::unique_ptr<Texture>(new Texture(m_renderer, _path));}

        void Start();
        void End();

        void Draw(const Texture& _text, ee::math::Rect<float> _destRect);
        void Draw(const Texture& _text, ee::math::Rect<float> _destRect, ee::math::Rect<float> _srcRect);
    
    };
}