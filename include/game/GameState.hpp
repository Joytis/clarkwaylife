//
// Created by Clark on 8/26/2016.
//

#ifndef LD36_GAMESTATE_HPP
#define LD36_GAMESTATE_HPP

#include "includes.hpp"
#include "engine.hpp"
#include "State.hpp"

// Is this necessary if it has already been pound included in "state.hpp"
#include <list>

class GameState : public State
{
private:
    int             test_;
    RenderObject*   bird_;
    RenderObject*   foo_;

public:

    GameState();
    ~GameState();

    void begin();
    void input();
    //void input(std::list<Event> eventList);
    void update();

    //NOTE(clark): TEST
    void update(unsigned int inp);

    void render();
    void end();
};


#endif //LD36_GAMESTATE_HPP

