//
// Created by Clark Burton Chambers on 9/24/16.
//

#ifndef __EntityManager_H_
#define __EntityManager_H_

#include "engine_includes.hpp"

#include "Entity.hpp"

class EntityManager
{
private:
    U32 next_id_;
    std::map<U32, Entity*> entities_;

public:
    EntityManager();

    Entity* get_entity();
    Entity* create_entity();
    void destroy_entity();
};

#endif //__EntityManager_H_
