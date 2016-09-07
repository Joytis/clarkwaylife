// Extension library includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// std includes
#include <iostream>

// Generic includes
#include "includes.hpp"

// TODO(clark): Potentially abstract these all into the engine?
#include "engine.hpp"

#include "states.hpp"
#include "file_strings.hpp"

// Texture Manager
// Should I just put a header wiht a bunch of
//      defined paths in here for the textures?

// TODO(clark): Define an assert statement.

using namespace std;

// Declare the variable that will be the engine.
// Externs B).
// Look into a better way to defining globals.
EngineObj eng;
int main()
{
    //
    // Initialize all components
    //======================================

    // Engine components
    // the ONLY instance of Engine object that you should //EVER// make

    // SDL components
    SDL_Event     sdl_event;
    bool          running           = true;

    // Initialize SDL
    //-------------------------------------------------------------
    if(eng.init() != GENERIC_SUCCESS)
    {
        running = false;
    }

    // Initialize the texture manager
    //-------------------------------------------------------------
    eng.renderer()->loadTexture("bird", CUTE_BIRD_JPG);

    // Initialize the state system
    //-------------------------------------------------------------
    eng.system()->add_state("game", new GameState());
    eng.system()->swap_state("game");

    //  Start main loop
    //======================================
    while(running)
    {
        // SDL Event loop
        while(SDL_PollEvent(&sdl_event) != 0)
        {
            if(sdl_event.type == SDL_QUIT)
            {
                running = false;
            }
            else if(sdl_event.type == SDL_KEYDOWN)
            {
                switch(sdl_event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                    default:
                        break;
                }
            }
        }

        eng.system()->input();
        eng.system()->update();
        eng.system()->render();
    }

    eng.close();

    return 0;
}
