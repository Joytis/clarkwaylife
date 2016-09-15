//
// Created by Clark Burton Chambers on 9/7/16.
//

#include "EngineObj.hpp"

EngineObj::EngineObj()
{
    // Do nothing until init is called
}

// TODO(clark): Eventually overload this to take in multiple flag combinations
int EngineObj::init()
{
    int ret_val = GENERIC_SUCCESS;

    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0) { ret_val = ERR_GENERIC_FAILED; }
    window_ = SDL_CreateWindow(
              "Clarkwaylife",
              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window_ == NULL) { ret_val = ERR_GENERIC_FAILED; }

    // Initialize IMG
    unsigned int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF;
    if( !( IMG_Init( imgFlags ) & imgFlags )) { ret_val = ERR_GENERIC_FAILED; }

    if(ret_val == GENERIC_SUCCESS)
    {
        system_ = new StateSystem();
        renderer_ = new Renderer(window_);
    }

    return ret_val;
}

Renderer* EngineObj::renderer()
{
    return renderer_;
}

StateSystem* EngineObj::system()
{
    return system_;
}

void EngineObj::render(RenderObject *robj)
{
    renderer_->render(robj);
}

void EngineObj::present()
{
    renderer_->present();
}

void EngineObj::close()
{
    system_->clear();

    SDL_DestroyWindow(window_);
    IMG_Quit();
    SDL_Quit();
}




