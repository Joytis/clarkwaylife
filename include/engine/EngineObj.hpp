//
// Created by Clark Burton Chambers on 9/7/16.
//

#ifndef __Engine_H_
#define __Engine_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "engine_includes.hpp"

#include "StateSystem.hpp"
#include "Renderer.hpp"

#define SCREEN_WIDTH   (640)
#define SCREEN_HEIGHT  (480)

class EngineObj
{
private:
    StateSystem*     system_;
    Renderer*        renderer_;
    SDL_Window*      window_;

public:

    EngineObj();

    int init();

    StateSystem* system();
    Renderer* renderer();

    void render(RenderObject* robj);

    void close();

};

extern EngineObj eng;

#endif //__Engine_H_
