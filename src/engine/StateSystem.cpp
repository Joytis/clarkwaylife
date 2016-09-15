//
// Created by Clark on 8/26/2016.
//

#include "StateSystem.hpp"

StateSystem::StateSystem(){}

int StateSystem::add_state(std::string key, State* value)
{
    if(value != NULL && states_.find(key) == states_.end())
    {
        states_[key] = value;
    }
    else
    {
        return ERR_GENERIC_FAILED;
    }
    return GENERIC_SUCCESS;
}

State* StateSystem::get_state(std::string key)
{
    if(states_.find(key) != states_.end())
    {
        return states_[key];
    }
    else
    {
        return NULL;
    }
}

int StateSystem::remove_state(std::string key)
{
    if(states_.find(key) != states_.end())
    {
        delete states_[key];
        states_.erase(key);
    }
    else
    {
        return ERR_GENERIC_FAILED;
    }
    return GENERIC_SUCCESS;
}

// Swaps the state to another state in the map
int StateSystem::swap_state(std::string key)
{
    if(states_.find(key) != states_.end())
    {
        current_ = states_[key];
    }
    else
    {
        return ERR_GENERIC_FAILED;
    }
    return GENERIC_SUCCESS;
}

void StateSystem::clear()
{
    // Delete all the states
    std::map<std::string, State*>::iterator it;
    for(it = states_.begin(); it != states_.end(); it++)
    {
        delete it->second;
    }
    states_.clear();
}

// Game function stuff
void StateSystem::input()
{
    current_->input();
}
void StateSystem::update()
{
    current_->update();
}

//NOTE(clark): TEST
void StateSystem::update(unsigned int input)
{
    current_->update(input);
}

void StateSystem::render()
{
    current_->render();
}