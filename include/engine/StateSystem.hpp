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

class StateSystem;
typedef State* (StateSystem::*memberf)(void) ;

class StateSystem
{
public:

    StateSystem();


    // Saw what you wanted to do at line 90. Unfortunately, c++ doesn't store Types
    //  at runtime, so to create a state we need to have a pointer reference
    //  to a function that will actually create an instance of the state.
    //  This should do that when you call all_states[key](args), and return
    //  a state of the respective type.
    template<typename T>
    void getStateCall() {
        return new T;
    }

    // Creates a mapping between a string and a type. Creates a new T when
    //  all_states[key] is called with respective typing.
    template<typename T>
    void addSystemState(std::string key) {
        if (all_states.find(key) == all_states.end()) {
            all_states[key] = StateSystem::getStateCall<T>; // Point to a facroty function
        }
        else{
            // TODO(n/a): Handle case
        }
    }

    int add_state(std::string key);
    State* get_state();
    State* get_previous_state();
    void back();
    void clear();

    void update();

    void handle_temp_states();

private:
    std::map<std::string, memberf> all_states;
    std::vector<State*> states;
    std::vector<std::string> temp_states;
    State *current;

};

#endif //__STATESYSTEM_HPP
