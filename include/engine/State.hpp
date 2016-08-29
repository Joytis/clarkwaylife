//
// Created by Clark on 8/26/2016.
//

#ifndef LD36_STATE_HPP
#define LD36_STATE_HPP


class State
{
public:
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif //LD36_STATE_HPP
