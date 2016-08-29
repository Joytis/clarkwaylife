//
// Created by Clark Burton Chambers on 8/24/16.
//
#include <map>
#include <string>

#include "TextureManager.hpp"


TextureManager::TextureManager(): renderer_(NULL) {}

SDL_Renderer* TextureManager::create_renderer(SDL_Window *window)
{
    //Create renderer for window
    renderer_ = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if( renderer_ == NULL )
    {
         return NULL;
    }
    //Initialize renderer color
    SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    return renderer_;
}

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

// Load a texture into memory from a given path and store it in the map under
//      a given key
int TextureManager::load_texture(std::string key, std::string path)
{
    SDL_Texture* tex = NULL;

    // Load up the image
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface == NULL) return ERR_GENERIC_FAILED;

    // Create the texture
    tex = SDL_CreateTextureFromSurface(renderer_, surface);
    if(tex == NULL) return ERR_GENERIC_FAILED;

    // Destroy the surface
    SDL_FreeSurface(surface);

    // Add it to the map
    return add_texture(key, tex);
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