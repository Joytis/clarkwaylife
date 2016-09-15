//
// Created by Clark Burton Chambers on 9/14/16.
//

#include "CSprite.hpp"


CSprite::CSprite(tex t) :
        Sprite::Sprite(t)
{

}

CSprite::CSprite(tex t, int x, int y, int w, int h) :
        Sprite::Sprite(t,x,y,w,h)
{

}

CSprite::~CSprite()
{

}
