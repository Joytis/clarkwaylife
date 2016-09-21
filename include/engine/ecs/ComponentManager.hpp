//
// Created by Clark Burton Chambers on 9/20/16.
//

#ifndef __EntityManager_H_
#define __EntityManager_H_



class ComponentManager
{
public:
    virtual void update() = 0;
    virtual void process_entities() = 0; // redundant?
};

#endif //__EntityManager_H_
