//
// Created by Clark on 8/26/2016.
//

#include "GameState.cpp"

#include "StateSystem.hpp"
StateSystem::StateSystem(){
    this.all_states['Game'] = GameState();
}

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
        return states.end()[-2]
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
    State* working_state = this.get_state();
    if(working_state) {
        // If this is a new state...
        if(!working_state->get_processed()) {
            working_state->begin();
            working_state->set_processed(true);
        }
        working_state->input();
        working_state->update();
        working_state->render();
        // If we're changing states
        if(!this.temp_states.empty()) {
            working_state->set_processed(false);
            working_state->end();
        }
    }
    this.handle_temp_states()
}

void StateSystem::handle_temp_states() {
    for(std::string key : this.temp_states) {
        if(key == POP_STR) {
            if(!this.states.empty()) {
                this.states.pop_back();
            }
        }
        else if(key == CLEAR_STR) {
            // Delete all the states
            while(!this.states.empty()) delete this.states.back(), this.states.pop_back();
        }
        else {
            State* new_state = this.all_states[key]();
            states.push_back(new_state);
        }
    }
}