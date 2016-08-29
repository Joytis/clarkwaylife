//
// Created by Clark on 8/26/2016.
//

#ifndef LD36_GAMESTATE_HPP
#define LD36_GAMESTATE_HPP

#include "includes.hpp"
#include "State.hpp"

class GameState : public State
{
private:
    int test_;
    SDL_Texture* bird_;
    SDL_Window* w_handle_;
public:

    GameState(SDL_Texture* tex, SDL_Window* win);

    void input();
    void update();
    void render();
};


#endif //LD36_GAMESTATE_HPP

