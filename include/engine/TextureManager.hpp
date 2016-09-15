//
// Created by Clark Burton Chambers on 8/24/16.
//

#ifndef __TextureManager_H_
#define __TextureManager_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <map>
#include <vector>

#include "engine_includes.hpp"

using namespace std;

class TextureManager
{
private:

    map<string, tex>    textures_;

public:

    TextureManager();

    int add_texture(string key, tex t);
    tex get_texture(string key);
    int remove_texture(string key);
    void clear();

};

#endif //__TextureManager_H_
