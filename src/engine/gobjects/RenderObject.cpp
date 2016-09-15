//
// Created by Clark Burton Chambers on 9/7/16.
//

#include "RenderObject.hpp"

RenderObject::RenderObject(Sprite spr):
    sprite_(spr)
{ }

RenderObject::~RenderObject() { }

//
Sprite* RenderObject::getSprite()
{
    return &sprite_;
}

//
void RenderObject::setSprite(Sprite spr)
{
    sprite_ = spr;
}

void RenderObject::update()
{
    // TODO(clark): Implement game space to screen space.
    sprite_.Rect(x_, y_, sprite_.Width(), sprite_.Height());
}

void RenderObject::Position(int x, int y)
{
    x_ = x;
    y_ = y;
}

void RenderObject::move(int x, int y)
{
    x_ += x;
    y_ += y;
}

std::tuple<int,int> RenderObject::Position()
{
    return std::make_tuple(x_, y_);
}
