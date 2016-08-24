#include <SDL2/SDL.h>

#include <iostream>

#include "includes.hpp"

// TODO(clark): Define an assert statement.

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

using namespace std;

int main()
{
    //
    // Initialize all components
    //======================================
    SDL_Window* window           = NULL;
    SDL_Event   event;


    // Initialize SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    window = SDL_CreateWindow(
                    "Clarkwaylife",
                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    assert(window);




    //
    // Close everything
    //======================================
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}