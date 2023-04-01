#include<stdio.h>
#include<stdbool.h>
#include<glad/glad.h>
#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>

int main(int argc, char *argv[]) {

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        exit(1);
    }
    
    //Pointer to SDL_Window
    SDL_Window *window = SDL_CreateWindow(

        "Game Window",              //Window title
        SDL_WINDOWPOS_CENTERED,     //x location, centered by using SDL macro
        SDL_WINDOWPOS_CENTERED,     //y location, centered by using SDL macro
        1024,                       //Width
        768,                        //Height
        SDL_WINDOW_OPENGL           //Flags. Using OpenGL in this case.

    );

    if (!window) {
        printf("Error initializing window: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_GL_CreateContext(window);

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        printf("Failed to load OpenGL: %s\n", SDL_GetError());
        exit(1);
    }

    puts("OpenGL Loaded Successfully.");
    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version: %s\n", glGetString(GL_VERSION));

    //Boolean used to determine if the game should continue running or not.
    bool game_ending = false;

    while (!game_ending) {

        SDL_Event event;

        //Poll for the quit event. If received, exit the game.
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    game_ending = true;
                    break;
                default:
                    break;
            }
        }

    }
    
    return 0;

}