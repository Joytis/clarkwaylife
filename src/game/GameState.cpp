//
// Created by Clark on 8/26/2016.
//
#include <SDL2/SDL.h>

#include "GameState.hpp"

GameState::GameState(SDL_Texture* tex, SDL_Window* win):
    w_handle_(win),
    bird_(tex)
{ }

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
    debug(DBG_STATES, "GameState: render");
}

