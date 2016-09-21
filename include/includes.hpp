#ifndef _INCLUDES_H
#define _INCLUDES_H

#include <exception>
#include <iostream>

#include "dbg.hpp"
#include "exceptions.hpp"

typedef unsigned char BYTE;
typedef unsigned int ULONG;

// If NULL not defined on platform, define as a null pointer with void * type
// TODO(clark): Do we want to just define our own null?
#ifndef NULL
#define NULL (void *)0
#endif

// Debug macro definitions
#define DBG_MAIN                    DEBUG_ON
#define DBG_STATES                  DEBUG_ON

#define S(val) (std::to_string(val))

extern unsigned int iinput;

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
