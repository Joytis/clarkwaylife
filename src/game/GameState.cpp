//
// Created by Clark on 8/26/2016.
//
#include <SDL2/SDL.h>

#include "GameState.hpp"

GameState::GameState()
{
    bird_ = new RenderObject();
    Sprite* spr = new Sprite(eng.renderer()->getTexture("bird"));
    bird_->setSprite(spr);
    //bird_->setSprite();
}

GameState::~GameState()
{
    if(bird_) delete bird_;
}

void GameState::input()
{
    debug(DBG_STATES, "GameState: input");
}

void GameState::update()
{
    debug(DBG_STATES, "GameState: update");
}
void GameState::render()
{
    eng.render(bird_);
    debug(DBG_STATES, "GameState: render");
}

