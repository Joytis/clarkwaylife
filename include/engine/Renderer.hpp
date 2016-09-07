//
// Created by Clark Burton Chambers on 9/6/16.
//

#ifndef __Renderer_H_
#define __Renderer_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

#include "engine_includes.hpp"
#include "TextureManager.hpp"

class Renderer
{
private:

    TextureManager  tm_;
    SDL_Renderer*   renderer_;
    SDL_Window*     w_handle_;

public:

    Renderer();
    Renderer(SDL_Window* win);

    int add_texture(std::string key, SDL_Texture* tex);
    int remove_texture(std::string key);
    int load_texture(std::string key, std::string path);
    int remove_texture(std::string key);

};

#endif //__Renderer_H_
