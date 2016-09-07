//
// Created by Clark on 8/26/2016.
//

#ifndef __STATESYSTEM_HPP
#define __STATESYSTEM_HPP

#include <map>
#include <vector>
#include <string>

#include "engine_includes.hpp"

#include "State.hpp"

class StateSystem
{
private:
    std::map<std::string, State*> states_;
    State *current_;

public:

    StateSystem();

    int add_state(std::string key, State* value);
    State* get_state(std::string key);
    int  remove_state(std::string key);
    int  swap_state(std::string key);
    void clear();

    void input();
    void update();
    void render();
};

#endif //__STATESYSTEM_HPP
