//
// Created by Clark on 8/26/2016.
//

#ifndef LD36_STATE_HPP
#define LD36_STATE_HPP

#include <list>

class State
{
private:
	bool processed;

public:
	virtual void begin() = 0;

    virtual void input(std::list<Event> eventList) = 0;
    virtual void update() = 0;

    // NOTE(clark): TEST
    virtual void update(unsigned int inp) = 0;

    virtual void render() = 0;

    virtual void end() = 0;
};

#endif //LD36_STATE_HPP
