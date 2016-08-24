//
// Created by Clark Burton Chambers on 6/26/16.
//

#ifndef _EXCEPTIONS_HPP
#define _EXCEPTIONS_HPP

#include "includes.hpp"

// Just a small decleration of exceptions.
// Nothing in stone, nothing really important. Mostly for example.

// NOTE(clark): These aren't permenant and hold no significant value.
struct e_general : public std::exception{
    virtual const char* what() const throw()
    {
        return "General Clarksouls Exception!";
    }
};

struct e_assert : public std::exception{
    virtual const char* what() const throw()
    {
        return "ASSERTION FAILED!!";
    }
};


#endif // _EXCEPTIONS_HPP
