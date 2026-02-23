#pragma once
#include "SDL3/SDL.h"
#include <stdexcept>


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
            ~Texture() {
                SDL_DestroyTexture(m_texture);
            };
            
            SDL_Texture* getTexture() const {return m_texture;}
            
            float getWidth() const {return m_width;}
            float getHeight() const {return m_height;}

        private:
        friend class Renderer;


    };


}