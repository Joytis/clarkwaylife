//
// Created by Clark Burton Chambers on 9/6/16.
//

#include "Renderer.hpp"

// TODO(clark): Create a way to change renderer settings

Renderer::Renderer(SDL_Window* win)
{
    w_handle_ = win;

    // TODO(clark): research second argument and how to use it.
    renderer_ = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
}

int Renderer::removeTexture(std::string key)
{
    if(tm_.remove_texture(key) == GENERIC_SUCCESS)
    {
        debug(ENGINE_DBG_RENDERER, "RE: Successfully removed texture!");
    }
    else
    {
        // TODO(clark): Error handling?
        debug(ENGINE_DBG_RENDERER, "RE: Could not remove texture from manager.");
    }
    return GENERIC_SUCCESS;
}



int Renderer::loadTexture(std::string key, std::string path)
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
    else
    {
        // TODO(clark): Error handling
        debug(ENGINE_DBG_RENDERER, "RE: Could not load texture.");
    }

    return 0;
}

// Error check this?
SDL_Texture* Renderer::getTexture(std::string key)
{
    return tm_.get_texture(key);
}

// TODO(clark): MAKE THIS BETTER. Super simple implementation
void Renderer::render(RenderObject* robj)
{
    /* render the current animation step of our shape */
    SDL_RenderCopy(renderer_, robj->getSprite()->getTexture(), NULL, NULL);
    SDL_RenderPresent(renderer_);
}

void Renderer::draw()
{
    // TODO(clark): implement
}
