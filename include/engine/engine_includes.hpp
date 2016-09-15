//
// Created by Clark Burton Chambers on 8/29/16.
//

#ifndef __engine_includes_H_
#define __engine_includes_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "dbg.hpp"

#define ENGINE_DEBUG_ON                 (1)
#define ENGINE_DEBUG_OFF                (0)

#define ENGINE_DBG_STATES               ENGINE_DEBUG_ON
#define ENGINE_DBG_RENDERER             ENGINE_DEBUG_ON
#define ENGINE_DBG_SPRITE               ENGINE_DEBUG_ON

#define ENGINE_CHROMA_KEY_COLOR         0, 0xFF, 0xFF

#define ERR_GENERIC_FAILED              (-1)
#define GENERIC_SUCCESS                 (1)

// Engine macros
#define ENG_DEL(ptr)        \
if(ptr)                     \
{                           \
    delete ptr;             \
    ptr = NULL;             \
}                           \

// Safely delete an array declared with
//   macro 'new'
#define ENG_DEL_ARR(ptr)    \
if(ptr)                     \
{                           \
    delete[] ptr;           \
    ptr = NULL;             \
}                           \

typedef struct tex
{
    SDL_Texture* texture;
    int w;
    int h;
} tex;

#endif //__engine_includes_H_
