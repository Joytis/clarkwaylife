//
// Created by Clark on 8/26/2016.
//

#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include <SDL2/SDL.h>

#include "engine_includes.hpp"
#include "dbg.hpp"

class Sprite
{
private:
    SDL_Texture* t_handle_;
    // Give it a rectangle to determine Sprite render position?
    //SDL_Rectangle rect_;
public:

    // Give it a handle to the texture.
    Sprite(SDL_Texture* tex);

    // Check the actual data types SDL uses.
    void setRectangle(int x, int y);

    // Gets the texture for now
    SDL_Texture* getTexture();
    void setTexture(SDL_Texture* tex);

};


#endif // ENGINE_SPRITE_HPP
