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
#include "RenderObject.hpp"

#define RENDER_BUFFER_LENGTH        (256)

class Renderer
{
private:

    TextureManager  tm_;
    SDL_Renderer*   renderer_;
    SDL_Window*     w_handle_;
    RenderObject*   render_buffer_[RENDER_BUFFER_LENGTH];
    // Abstract render buffers into another class to simplify renderer?
    unsigned int    rbuffer_index_;


public:

    Renderer(SDL_Window* win);

    int removeTexture(std::string key);
    int loadTexture(std::string key, std::string path);
    SDL_Texture* getTexture(std::string key);


    // NOTE(clark): Should we sort the renderer buffer by texture, or make seperate render buffers for each texture.
    // NOTE(clark): We could also, upon loading of textures, create a buffer for each respective texture in memory
    // TODO(clark): These methods are up for dicsussiona nd testing
    // Add object to the render buffer?
    void render(RenderObject* robj);
    // Draws all objects in the buffer?
    void draw();

};

#endif //__Renderer_H_
