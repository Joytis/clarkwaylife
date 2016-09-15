//
// Created by Clark Burton Chambers on 9/7/16.
//

#ifndef __RenderObject_H_
#define __RenderObject_H_

#include "engine_includes.hpp"
#include "Sprite.hpp"
#include "GameObject.hpp"

#include <tuple>

// TODO(clark): How to render the objects using the renderer?
class RenderObject : public GameObject
{
private:

protected:
    // TODO(clark): Is there a way to do this without a pointer?
    Sprite  sprite_;

    // the IN-GAME coordinates for the game obejct. NOT the same as screen
    int     x_;
    int     y_;

public:
    // Should this be a pointer or just a copy?
    RenderObject(Sprite spr);
    ~RenderObject();

    // TODO(clark):Possibly abstract these into a PosObject? Inherit from gobject?
    void Position(int x, int y);
    std::tuple<int,int> Position();

    Sprite* getSprite();
    void setSprite(Sprite spr);

    void update();
    void move(int x, int y);

};

#endif //__RenderObject_H_
