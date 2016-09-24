//
// Created by Clark Burton Chambers on 9/20/16.
//

#ifndef __Component_H_
#define __Component_H_


// Since C++ is nice and doesn't force us to hack the compiler,
//  we can just use inheritance with Components
typedef struct Component {
} Component;

typedef struct PositionComponent : Component {
    float x;
    float y;
} PositionComponent;

typedef struct CollisionComponent : Component {

} CollisionComponent;

typedef struct TextureComponent : Component {

} TextureComponent;

// Probably get something from the texture manager?
typedef struct SpriteComponent : Component {
    PositionComponent position;
    TextureComponent texture;

} SpriteComponent;

typedef struct AudioComponent : Component {

} AudioComponent;

typedef struct ScriptComponent : Component {

} ScriptComponent;

typedef struct LayerComponent : Component {

} LayerComponent;

typedef struct VelocityComponent : Component {

} VelocityComponent;

typedef struct BoysComponent : Component {

} BoysComponent;

typedef struct MenuComponent : Component {

} MenuComponent;

typedef struct AnimationComponent : Component {

} AnimationComponent;

typedef struct AIComponent : Component {

} AIComponent;

#endif //__Component_H_
