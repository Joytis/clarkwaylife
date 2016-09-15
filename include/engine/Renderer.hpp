//
// Created by Clark Burton Chambers on 9/6/16.
//

#ifndef __Renderer_H_
#define __Renderer_H_

#include <string>

#include "engine_includes.hpp"
#include "TextureManager.hpp"
#include "RenderObject.hpp"


#define REND_NONE                   (0)
#define REND_KEYCOLOR               (1 << 1)

#define REND_

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
    int loadTexture(std::string key, std::string path, int flags);
    tex getTexture(std::string key);


    // NOTE(clark): Should we sort the renderer buffer by texture, or make seperate render buffers for each texture.
    // NOTE(clark): We could also, upon loading of textures, create a buffer for each respective texture in memory
    // TODO(clark): These methods are up for dicsussiona nd testing
    // Add object to the render buffer?
    void clear();

    void render(RenderObject *robj);
    // Draws all objects in the buffer?
    //void draw(RenderObject* robj);

    void present();

};

#endif //__Renderer_H_
