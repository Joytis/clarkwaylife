//
// Created by Clark on 8/26/2016.
//

#include "StateSystem.hpp"

StateSystem::StateSystem(){
    //this.all_states['Game'] = GameState();
}

// Is there a way to pass arguments into a constructor using this method?
//int StateSystem::add_state(std::string key) {
//    if(all_states.find(key) == all_states.end()) {
//        return ERR_GENERIC_FAILED;
//    }
//    else {
//        temp_states.push_back(key);
//    }
//    return GENERIC_SUCCESS;
//}

State* StateSystem::get_state() {
    if(!states.empty()) {
        return states.back();
    }
    else {
        return NULL;
    }
}

State* StateSystem::get_previous_state() {
    if(states.size() > 1) {
        return states.end()[-2];
    }
    else {
        return NULL;
    }
}

void StateSystem::back() {
    temp_states.push_back(std::make_pair(STSYSTEM_POP_STACK, nullptr));
}

void StateSystem::clear() {
    temp_states.push_back(std::make_pair(STSYSTEM_CLEAR_STACK, nullptr));
}

// DON"T YOU DARE CALL THIS IN STATE::BEGIN(); (or in the constructor)
void StateSystem::push(State* sta) {
    auto tup = std::make_pair(STSYSTEM_PUSH_STACK, sta);
    temp_states.push_back(tup);
}

//updates the current state at every tick
void StateSystem::update() {
    State* working_state = get_state();
    if(working_state) {
        // If this is a new state...
        working_state->input();
        working_state->update();
        working_state->render();
        // If we're changing states
    }
    handle_temp_states();
}

// Find a way to pass arguments into this?
void StateSystem::handle_temp_states() {
    for(stack_type tup : temp_states) {
        switch(tup.first) {
            case STSYSTEM_POP_STACK:
                if (!states.empty()) {
                    State* working_state = get_state();
                    get_state()->end();
                    delete working_state;
                    states.pop_back();
                }
                break;
            case STSYSTEM_CLEAR_STACK:
                // Delete all the states
                while (!states.empty()) delete states.back(), states.pop_back();
                break;
            case STSYSTEM_PUSH_STACK:
                states.push_back(tup.second);
                tup.second->begin();
                break;
            default:
                debug(ENGINE_DBG_STATES, "SS: Should not be here. :I");
                break;
        }
    }
    temp_states.clear();
}