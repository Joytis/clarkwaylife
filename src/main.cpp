// Extension library includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// std includes
#include <iostream>

// Generic includes
#include "includes.hpp"

// TODO(clark): Potentially abstract these all into the engine?
#include "engine.hpp"

// Game states
#include "states.hpp"

#include "file_strings.hpp"

// Texture Manager
// Should I just put a header wiht a bunch of
//      defined paths in here for the textures?

// TODO(clark): Define an assert statement.

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

using namespace std;

int main()
{
    //
    // Initialize all components
    //======================================

    // Engine components
    StateSystem         system_;
    TextureManager      t_manager_;

    // SDL components
    SDL_Window*   window            = NULL;
    SDL_Renderer* renderer          = NULL;
    SDL_Event     sdl_event;
    ULONG         imgFlags          = 0;
    bool          running           = true;

    // Initialize SDL
    //-------------------------------------------------------------
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0) { running = false; }
    window = SDL_CreateWindow(
            "Clarkwaylife",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    assert(window);

    // Initialize IMG
    imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF;
    if( !( IMG_Init( imgFlags ) & imgFlags ) & imgFlags ) { running = false; }


    // Initialize the texture manager
    //-------------------------------------------------------------
    renderer = t_manager_.create_renderer(window);
    t_manager_.load_texture("bird", CUTE_BIRD_JPG);

    // Initialize the state system
    //-------------------------------------------------------------
    SDL_Texture* tmp = t_manager_.get_texture("bird");
    system_.add_state("game", new GameState(tmp, window));
    system_.swap_state("game");

    //
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

        system_.input();
        system_.update();
        system_.render();
        //Clear screen
        SDL_RenderClear( renderer );

        //Render texture to screen
        SDL_RenderCopy( renderer, t_manager_.get_texture("bird"), NULL, NULL );

        //Update screen
        SDL_RenderPresent( renderer );
    }

    //
    // Close everything
    //======================================

    // State system
    system_.clear();

    // SDL
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}