#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Erreur SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Ma Fenêtre SDL3", 800, 600, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Erreur création fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Boucle d'événements
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
    }

    // Nettoyage
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
