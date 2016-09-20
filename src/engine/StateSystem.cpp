//
// Created by Clark on 8/26/2016.
//

#include "StateSystem.hpp"

StateSystem::StateSystem(){
    //this.all_states['Game'] = GameState();
}

// Is there a way to pass arguments into a constructor using this method?
int StateSystem::add_state(std::string key) {
    if(all_states.find(key) == all_states.end()) {
        return ERR_GENERIC_FAILED;
    }
    else {
        temp_states.push_back(key);
    }
    return GENERIC_SUCCESS;
}

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
    temp_states.push_back(POP_STR);
}

void StateSystem::clear() {
    temp_states.push_back(CLEAR_STR);
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
    for(std::string key : temp_states) {
        if(key == POP_STR) {
            if(!states.empty()) {
                states.front()->end();
                states.pop_back();
            }
        }
        else if(key == CLEAR_STR) {
            // Delete all the states
            while(!states.empty()) delete states.back(), states.pop_back();
        }
        else {
            int k; // temporary stuff
            State* new_state = all_states[key](); // Create a new state
            states.push_back(new_state);
            new_state->begin();
        }
    }
}