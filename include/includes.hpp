#ifndef _INCLUDES_H
#define _INCLUDES_H

#include <exception>
#include <iostream>

#include "dbg.hpp"
#include "exceptions.hpp"

// If NULL not defined on platform, define as a null pointer with void * type
// TODO(clark): Do we want to just define our own null?
#ifndef NULL
#define NULL (void *)0
#endif

#define S(val) (std::to_string(val))

// Safely delete a pointer to an object
//  declared with 'new'
#define DEL(ptr)        \
if(ptr)                 \
{                       \
    delete ptr;         \
    ptr = NULL;         \
}                       \

// Safely delete an array declared with
//   macro 'new'
#define DEL_ARR(ptr)    \
if(ptr)                 \
{                       \
    delete[] ptr;       \
    ptr = NULL;         \
}                       \



#endif // _INCLUDES_H
