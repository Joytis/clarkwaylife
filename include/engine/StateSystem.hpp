//
// Created by Clark on 8/26/2016.
//

#ifndef __STATESYSTEM_HPP
#define __STATESYSTEM_HPP

#include <map>
#include <vector>
#include <string>
#include <utility>

#include "engine_includes.hpp"

#include "State.hpp"

#define STSYSTEM_POP_STACK          (0)
#define STSYSTEM_CLEAR_STACK        (1)
#define STSYSTEM_PUSH_STACK         (2)

typedef std::pair<BYTE, State*> stack_type;

class StateSystem
{

private:
    std::vector<State*> states;
    std::vector<stack_type> temp_states;
    State *current;

public:

    //Constructors
    StateSystem();

    // Stack manipulatirs
    void push(State* sta);
    void back();
    void clear();
    void handle_temp_states();

    // State getters
    State* get_state();
    State* get_previous_state();


    void update();

};

#endif //__STATESYSTEM_HPP
