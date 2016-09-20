// Extension library includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// std includes
#include <iostream>

// Generic includes
#include "includes.hpp"

#include "engine.hpp"

#include "states.hpp"
#include "file_strings.hpp"

using namespace std;

// Declare the variable that will be the engine.
// Look into a better way to defining globals.
// the ONLY instance of Engine object that you should //EVER// make
EngineObj eng;

//void StateSystem::addSystemState<GameState>(std::string key);

//===================================================================================//
// -------------------- Clarkwaylife: Start of Main ---------------------------------//
//===================================================================================//
int main()
{
    //
    // Initialize all components
    //======================================
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
    eng.renderer()->loadTexture("bird", CUTE_BIRD_JPG, REND_NONE);
    eng.renderer()->loadTexture("foo", FOO_PNG, REND_KEYCOLOR);

    // Initialize the state system
    //-------------------------------------------------------------
    eng.system()->addSystemState<GameState>("game");


    //======================================//
    //  Start main loop                     //
    //======================================//
    unsigned int input;
    while(running)
    {
        // Improv input
        const Uint8* keyb = SDL_GetKeyboardState(NULL);

        input = 0;


        if(keyb[SDL_SCANCODE_UP])
        {
            input |= (1 << 0);
        }
        if(keyb[SDL_SCANCODE_DOWN])
        {
            input |= (1 << 1);
        }
        if(keyb[SDL_SCANCODE_LEFT])
        {
            input |= (1 << 2);
        }
        if(keyb[SDL_SCANCODE_RIGHT])
        {
            input |= (1 << 3);
        }

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

        // Game input, update, render
        // TODO(clark): Determine whether or not it is worth having
        //              a dedicated input step instead of jut having update
        //              and render.

        // TODO(clark): consolidate these into methods that make sense.
        //              eng.system()->update()
        //              eng.system()->render()
        //              eng.present()

        // Clear the engine renderer
        //===========================
        eng.renderer()->clear();

        // Update the state system
        //===========================
        //eng.system()->input();
        eng.system()->update();

        // Render the State system
        //===========================
        //eng.system()->render();

        // Presend to Screen
        //===========================
        eng.present();
    }

    eng.close();

    return 0;
}
