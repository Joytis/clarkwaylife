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

#define POP_STR "pop"
#define CLEAR_STR "clear"

class StateSystem
{
private:
    std::map<std::string, State*> all_states;
    std::vector<State*> states;
    std::vector<State*> temp_states;
    State *current;

public:

    StateSystem();

    int add_state(std::string key);
    State* get_state();
    State* get_previous_state();
    void back();
    void clear();

    void update();
    void handle_temp_states();
};

#endif //__STATESYSTEM_HPP
