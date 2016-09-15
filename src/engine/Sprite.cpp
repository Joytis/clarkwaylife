//
// Created by Clark on 8/26/2016.
//

#include "Sprite.hpp"

// Give it a handle to the texture.
Sprite::Sprite(tex t)
{
    texture_ = t;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = t.w;
    rect_.h = t.h;
    // Do nothing with rect
    // rect_;
}

Sprite::Sprite(tex t, int x, int y, int w, int h){
    texture_ = t;
    rect_.x = x;
    rect_.y = y;
    rect_.w = w;
    rect_.h = h;
}

// Placeholder Destructor
Sprite::~Sprite() { }

int Sprite::X()
{
    return rect_.x;
}

int Sprite::Y()
{
    return rect_.y;
}

int Sprite::Width()
{
    return rect_.w;
}

int Sprite::Height()
{
    return rect_.h;
}

SDL_Rect* Sprite::Rect()
{
    return &rect_;
}

void Sprite::Rect(int x, int y, int w, int h)
{
    rect_.x = x;
    rect_.y = y;
    rect_.w = w;
    rect_.h = h;
}


tex Sprite::Texture()
{
    return texture_;
}

void Sprite::Texture(tex t)
{
    texture_ = t;
    rect_.w = t.w;
    rect_.h = t.h;
}