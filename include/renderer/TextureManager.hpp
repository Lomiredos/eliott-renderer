#pragma once
#include <unordered_map>

#include "renderer/Texture.hpp"

#include <string>
#include <memory>
struct SDL_Renderer;

namespace ee::renderer
{

    class TextureManager
    {

    private:
        std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
        SDL_Renderer* m_renderer =  nullptr;

    public:



        std::shared_ptr<Texture> addTexture(std::string _name, const char *_path)
        {
            if (m_textures.find(_name) != m_textures.end()){
                return m_textures[_name]; 
            }
            std::shared_ptr<Texture> texture = std::shared_ptr<Texture>(new Texture(m_renderer, _path));        
            m_textures[_name] = texture;

            return m_textures[_name];
        }

        std::shared_ptr<Texture> getTexture(std::string _name){

            if (m_textures.find(_name) == m_textures.end()){
                return nullptr; 
            }
            return m_textures[_name];
        }



        ~TextureManager(){
            m_textures.clear();
        }

        TextureManager() = default;
        void init(SDL_Renderer* _rend){
            m_renderer = _rend;
        }

        TextureManager(const TextureManager &) = delete;
        TextureManager &operator=(const TextureManager &) = delete;
    };

}
