//
// Created by Clark Burton Chambers on 9/6/16.
//

#include "Renderer.hpp"

// TODO(clark): Create a way to change renderer settings

Renderer::Renderer()
{
    w_handle_ = NULL;
    renderer_ = NULL;
    // TODO(clark): Throw an error here? Shouldn't ever get to this.
}

Renderer::Renderer(SDL_Window* win)
{
    w_handle_ = win;
    renderer_ = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
}



int Renderer::remove_texture(std::string key)
{
    if(tm_.remove_texture(key) == GENERIC_SUCCESS)
    {
        debug(ENGINE_DBG_RENDERER, "RE: Successfully removed texture!");
    }
    else
    {
        // TODO(clark): Error handling?
    }
}



int Renderer::load_texture(std::string key, std::string path)
{
    SDL_Surface* surface = NULL;
    SDL_Texture* tex = NULL;

    if(renderer_ != NULL && w_handle_ != NULL)
    {
        surface = IMG_Load(path.c_str());
        tex = SDL_CreateTextureFromSurface(renderer_, surface);

        // TODO(clark): Check for errors coming from texture manager here
        tm_.add_texture(key,tex);
        SDL_FreeSurface(surface);
    }

    return 0;
}
