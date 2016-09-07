//
// Created by Clark Burton Chambers on 9/7/16.
//

#include "RenderObject.hpp"

RenderObject::RenderObject()
{

}

RenderObject::~RenderObject()
{
    // NOTE(clark): This could be incorrect. Depending on where Sprites
    //              are created.
    if(sprite_)
    {
        delete sprite_;
    }
}

Sprite* RenderObject::getSprite()
{
    return sprite_;
}

void RenderObject::setSprite(Sprite *spr)
{
    sprite_ = spr;
}

void RenderObject::update()
{

}
