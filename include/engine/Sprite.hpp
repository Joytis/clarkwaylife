//
// Created by Clark on 8/26/2016.
//

#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include "engine_includes.hpp"
#include "dbg.hpp"

class Sprite
{
private:

protected:
    // Texture dished out by the manager.
    // Contains texture pointer and the natural w/h of texture
    tex             texture_;


    // The ON-SCREEN position of the Sprite. Used for SDL rendering.
    SDL_Rect        rect_;

    // Give it a rectangle to determine Sprite render position?
    //SDL_Rectangle rect_;

public:

    // Give it a handle to the texture.
    Sprite(tex t);
    Sprite(tex t, int x, int y, int w, int h);
    ~Sprite();

    // Check the actual data types SDL uses.
    SDL_Rect* Rect();
    void Rect(int x, int y, int w, int h);
    int Y();
    int X();
    int Width();
    int Height();

    // Gets the texture for now
    tex Texture();
    void Texture(tex t);
};


#endif // ENGINE_SPRITE_HPP
