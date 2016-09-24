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
    U32 cur_id_;
    std::map<U32, Entity*> entities_;

    U32 get_next_id();

public:
    EntityManager();

    Entity* get_entity(U32 id);
    Entity* create_entity();
    void destroy_entity(U32 id);
};

#endif //__EntityManager_H_
