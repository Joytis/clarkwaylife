//
// Created by Clark on 8/26/2016.
//
#include <SDL2/SDL.h>

#include "GameState.hpp"

GameState::GameState()
{
    Sprite spr(eng.renderer()->getTexture("bird"));
    bird_ = new RenderObject(spr);
    bird_->Position(0,0);

    spr.Texture(eng.renderer()->getTexture("foo"));
    foo_ = new RenderObject(spr);
    foo_->Position(0,0);
}

GameState::~GameState()
{
    if(bird_) delete bird_;
}

void GameState::begin()
{
    //nothing much
}

void GameState::end()
{
    //nothing much
}

void GameState::input()
{

}

//void GameState::input(std::list<Event> eventList)
//{
//    //for(Event inp : eventList) {
//        if(inp != 0)
//        {
//            if(inp & (1 << 0))
//            {
//                bird_->move(0, -10);
//                foo_->move(0, -15);
//            }
//            if(inp & (1 << 1))
//            {
//                bird_->move(0, 10);
//                foo_->move(0, 15);
//            }
//            if(inp & (1 << 2))
//            {
//                bird_->move(-10, 0);
//                foo_->move(-15, 0);
//            }
//            if(inp & (1 << 3))
//            {
//                bird_->move(10, 0);
//                foo_->move(15, 0);
//            }
//        }
//    //}
//    // debug(DBG_STATES, "GameState: input");
//}

void GameState::update()
{
    // debug(DBG_STATES, "GameState: update");
}

//NOTE(clark): TEST
// THIS SHOULD BE IN INPUT, NO?
void GameState::update(unsigned int inp)
{
    bird_->update();
    foo_->update();
}

void GameState::render()
{
    eng.render(bird_);
    eng.render(foo_);
    // debug(DBG_STATES, "GameState: render");
}

