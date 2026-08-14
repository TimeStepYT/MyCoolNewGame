#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Global.hpp"
#include "Game.hpp"
#include "Mouse.hpp"

Game* game = nullptr;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
    SDL_SetAppMetadata("Balls", "1.0", "com.timestepyt.balls");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("Balls", 1280, 720, SDL_WINDOW_SURFACE_VSYNC_DISABLED, &global::window, &global::renderer)) {
        SDL_Log("Couldn't create window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_SetRenderLogicalPresentation(global::renderer, 1280, 720, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    SDL_SetRenderDrawBlendMode(global::renderer, SDL_BLENDMODE_ADD);
    game = new Game();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    switch (event->type) {
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
        Mouse::get().setClicked(static_cast<MouseButtonID>(event->button.button));
        break;
    case SDL_EVENT_MOUSE_BUTTON_UP:
        Mouse::get().setNotClicked(static_cast<MouseButtonID>(event->button.button));
        break;
    case SDL_EVENT_MOUSE_MOTION:
        Mouse::get().setPosition({event->motion.x, event->motion.y});
        break;
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    default:
        break;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    game->update();
    
    //const float fpsCap = 240.f;
    //SDL_Delay((1.f / fpsCap) * 1000.f);
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    delete game;
}