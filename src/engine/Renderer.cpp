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



int Renderer::loadTexture(std::string key, std::string path, int flags)
{
    SDL_Surface* surface = NULL;
    tex texture;

    if(renderer_ != NULL && w_handle_ != NULL)
    {
        surface = IMG_Load(path.c_str());
        if(surface == NULL)
        {
            debug(ENGINE_DBG_RENDERER, "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError())
        }
        else
        {
            texture.h = surface->h;
            texture.w = surface->w;

            // Key out a given color. Defined in engine_includes
            if(flags & REND_KEYCOLOR)
            {
                SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, ENGINE_CHROMA_KEY_COLOR));
            }
            texture.texture = SDL_CreateTextureFromSurface(renderer_, surface);

            // TODO(clark): Check for errors coming from texture manager here
            tm_.add_texture(key,texture);
        }

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
tex Renderer::getTexture(std::string key)
{
    return tm_.get_texture(key);
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
}

// TODO(clark): MAKE THIS BETTER. Super simple implementation
void Renderer::render(RenderObject* robj)
{
    Sprite* spr= robj->getSprite();
    SDL_Rect* rec = spr->Rect();
    SDL_Texture* texture = spr->Texture().texture;

    SDL_RenderCopy(renderer_, texture, NULL, rec);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer_);
}