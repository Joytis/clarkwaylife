//
// Created by Clark Burton Chambers on 9/24/16.
//

#ifndef __Entity_H_
#define __Entity_H_

#include <map>

#include "engine_includes.hpp"
#include "Components.hpp"

typedef std::map<U32, Component*>  cp_map;

typedef struct Entity{
    U32 id;
    cp_map cm;
} Entity;

#endif //__Entity_H_
