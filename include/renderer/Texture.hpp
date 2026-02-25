#pragma once

#include <stdexcept>

struct SDL_Texture;
struct SDL_Renderer;
namespace ee::renderer{


    class Texture {

        private:
            SDL_Texture* m_texture = nullptr;

            float m_width = 0;
            float m_height = 0;

            Texture(SDL_Renderer* _renderer, const char* _path);
            
            
            Texture(const Texture&) = delete;
            Texture& operator=(const Texture&) = delete;
            
            public:
            ~Texture();
            
            SDL_Texture* getTexture() const {return m_texture;}
            
            float getWidth() const {return m_width;}
            float getHeight() const {return m_height;}

        private:
        friend class Renderer;
    };
}