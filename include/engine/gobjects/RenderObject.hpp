//
// Created by Clark Burton Chambers on 9/7/16.
//

#ifndef __RenderObject_H_
#define __RenderObject_H_

#include <SDL2/SDL.h>

#include "engine_includes.hpp"
#include "Sprite.hpp"
#include "GameObject.hpp"

// TODO(clark): How to render the objects using the renderer?
class RenderObject : public GameObject
{
private:

protected:
    // TODO(clark): Is there a way to do this without a pointer?
    Sprite* sprite_;

public:
    // Should this be a pointer or just a copy?
    RenderObject();
    ~RenderObject();

    Sprite* getSprite();
    void setSprite(Sprite* spr);

    void update();
};

#endif //__RenderObject_H_
