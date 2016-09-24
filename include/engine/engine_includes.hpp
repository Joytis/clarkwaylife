//
// Created by Clark Burton Chambers on 8/29/16.
//

#ifndef __engine_includes_H_
#define __engine_includes_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "dbg.hpp"

// Convenient number type definitions
typedef uint8_t     BYTE;
typedef uint16_t    U16;
typedef uint32_t    U32;
typedef uint64_t    U64;


#define ENGINE_DEBUG_ON                 (1)
#define ENGINE_DEBUG_OFF                (0)

#define EDBG_ENMAN  		ENGINE_DEBUG_ON
#define EDBG_TXMAN    		ENGINE_DEBUG_ON
#define EDBG_EVMAN			ENGINE_DEBUG_ON
#define EDBG_SNMAN			ENGINE_DEBUG_ON	
#define EDBG_INMAN			ENGINE_DEBUG_ON

#define EDBG_AISYS			ENGINE_DEBUG_ON
#define EDBG_ANSYS			ENGINE_DEBUG_ON
#define EDBG_AUSYS			ENGINE_DEBUG_ON
#define EDBG_CLSYS			ENGINE_DEBUG_ON
#define EDBG_CMSYS			ENGINE_DEBUG_ON
#define EDBG_PHSYS			ENGINE_DEBUG_ON
#define EDBG_RNSYS			ENGINE_DEBUG_ON
#define EDBG_SCSYS			ENGINE_DEBUG_ON

#define EDBG_STSYS          ENGINE_DEBUG_ON

#define ENGINE_CHROMA_KEY_COLOR         0, 0xFF, 0xFF

#define ERR_GENERIC_FAILED              (-1)
#define GENERIC_SUCCESS                 (1)

typedef unsigned char BYTE;

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
