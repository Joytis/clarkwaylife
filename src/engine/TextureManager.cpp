//
// Created by Clark Burton Chambers on 8/24/16.
//
#include <map>
#include <string>

#include "TextureManager.hpp"


TextureManager::TextureManager() {}

// Add a loaded texture into the texture map
int TextureManager::add_texture(std::string key, SDL_Texture* value)
{
    if(value != NULL && textures_.find(key) == textures_.end())
    {
        textures_[key] = value;
    }
    else
    {
        return ERR_GENERIC_FAILED;
    }
    return GENERIC_SUCCESS;
}

// Returns a texture from a key
SDL_Texture* TextureManager::get_texture(std::string key)
{
    if(textures_.find(key) != textures_.end())
    {
        return textures_[key];
    }
    else
    {
        return NULL;
    }
}

// Removes a texture fomr the map
int TextureManager::remove_texture(std::string key)
{
    if(textures_.find(key) != textures_.end())
    {
        SDL_DestroyTexture(textures_[key]);
        textures_.erase(key);
    }
    else
    {
        return ERR_GENERIC_FAILED;
    }
    return GENERIC_SUCCESS;
}


// Clears all textures from the map
void TextureManager::clear()
{
    std::map<string, SDL_Texture*>::iterator it;
    for(it = textures_.begin(); it != textures_.end(); it++)
    {
        SDL_DestroyTexture(it->second);
    }
    textures_.clear();
}