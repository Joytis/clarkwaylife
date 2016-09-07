//
// Created by Clark on 8/26/2016.
//

#include "Sprite.hpp"

// Give it a handle to the texture.
Sprite::Sprite(SDL_Texture* tex)
{
    t_handle_ = tex;
    // Do nothing with rect
    // rect_;
}

// Check the actual data types SDL uses.
void Sprite::setRectangle(int x, int y)
{
    // Do nothing for now. We just want a texture handle.
}

SDL_Texture* Sprite::getTexture()
{
    return t_handle_;
}

void Sprite::setTexture(SDL_Texture* tex)
{
    if(tex != NULL)
    {
        t_handle_ = tex;
    }
    else
    {
        // TODO(clark): Error handling.
        debug(ENGINE_DBG_SPRITE, "Can't set texture to NULL!");
    }
}