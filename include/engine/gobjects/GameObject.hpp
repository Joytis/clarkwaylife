//
// Created by Clark Burton Chambers on 9/7/16.
//

#ifndef __GameObject_H_
#define __GameObject_H_

// TODO(clark): Discuss what should be in a game object? Should all GameObjects be renderable?
class GameObject
{
private:
public:
    virtual void update() = 0;
};

#endif //__GameObject_H_
