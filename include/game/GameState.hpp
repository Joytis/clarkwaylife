//
// Created by Clark on 8/26/2016.
//

#ifndef LD36_GAMESTATE_HPP
#define LD36_GAMESTATE_HPP

#include "includes.hpp"
#include "engine.hpp"
#include "State.hpp"

class GameState : public State
{
private:
    int             test_;
    RenderObject*   bird_;

public:

    GameState();
    ~GameState();

    void input();
    void update();
    void render();
};


#endif //LD36_GAMESTATE_HPP

