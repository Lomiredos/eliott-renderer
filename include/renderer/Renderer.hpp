#pragma once
#include <string>
#include <memory>

#include "SDL3/SDL.h"
#include "Texture.hpp"

namespace ee::renderer{



    class Renderer{
        
        private:
            SDL_Window* m_window = nullptr;
            SDL_Renderer* m_renderer = nullptr;            
            std::string m_name;
            float m_width;
            float m_height;

        public:

        Renderer( float _width, float _height, const char* _name)
         : m_name(_name), m_width(_width), m_height(_height) 
        {
            m_window = SDL_CreateWindow(m_name.c_str(), m_width, m_height, 0);
            
            if (!m_window)
                throw std::runtime_error(SDL_GetError());
            
            m_renderer = SDL_CreateRenderer(m_window, nullptr);

            if (!m_renderer)
                throw std::runtime_error(SDL_GetError());



        }
        ~Renderer() {
            SDL_DestroyWindow(m_window);
            SDL_DestroyRenderer(m_renderer);
        }


        std::unique_ptr<Texture> createTexture(const char* _path) {return std::unique_ptr<Texture>(new Texture(m_renderer, _path));}

        void Start();
        void End();

        void Draw(const Texture& _text, SDL_FRect _destRect);
        void Draw(const Texture& _text, SDL_FRect _destRect, SDL_FRect _srcRect);
    
    };
}