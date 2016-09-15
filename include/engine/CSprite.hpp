//
// Created by Clark Burton Chambers on 9/14/16.
//

#ifndef __CSprite_H_
#define __CSprite_H_

#include "engine_includes.hpp"
#include "Sprite.hpp"

class CSprite : public Sprite
{
private:

protected:

public:
    CSprite(tex t);
    CSprite(tex t, int x, int y, int w, int h);
    ~CSprite();

    // called in destructor.
    void free();
};

#endif //__CSprite_H_
