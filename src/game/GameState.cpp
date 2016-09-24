//
// Created by Clark on 8/26/2016.
//
#include <SDL2/SDL.h>

#include "GameState.hpp"

GameState::GameState()
{
}

GameState::~GameState()
{
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
}

void GameState::render()
{
    // debug(DBG_STATES, "GameState: render");
}

