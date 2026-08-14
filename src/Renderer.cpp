#include "Renderer.hpp"
#include "Global.hpp"

void Renderer::clear() {
    SDL_RenderClear(global::renderer);
}

void Renderer::setDrawColor(uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(global::renderer, r, g, b, 255);
}

void Renderer::drawRect(float x, float y, float w, float h, uint8_t r, uint8_t g, uint8_t b) {
    Renderer::setDrawColor(r, g, b);
    SDL_FRect rect{x, y, w, h};
    SDL_RenderFillRect(global::renderer, &rect);
}

void Renderer::drawCircle(float x, float y, float radius, uint8_t r, uint8_t g, uint8_t b) {
    Renderer::setDrawColor(r, g, b);
    
    const int32_t diameter = (radius * 2);

    int32_t xPart = (radius - 1);
    int32_t yPart = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (xPart >= yPart) {
        //  Each of the following renders an octant of the circle
        SDL_RenderPoint(global::renderer, x + xPart, y - yPart);
        SDL_RenderPoint(global::renderer, x + xPart, y + yPart);
        SDL_RenderPoint(global::renderer, x - xPart, y - yPart);
        SDL_RenderPoint(global::renderer, x - xPart, y + yPart);
        SDL_RenderPoint(global::renderer, x + yPart, y - xPart);
        SDL_RenderPoint(global::renderer, x + yPart, y + xPart);
        SDL_RenderPoint(global::renderer, x - yPart, y - xPart);
        SDL_RenderPoint(global::renderer, x - yPart, y + xPart);

        if (error <= 0) {
            ++yPart;
            error += ty;
            ty += 2;
        }

        if (error > 0) {
            --xPart;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

// https://gist.github.com/Gumichan01/332c26f6197a432db91cc4327fcabb1c
void Renderer::fillCircle(float x, float y, float radius, uint8_t r, uint8_t g, uint8_t b) {
    Renderer::setDrawColor(r, g, b);

    int offsetx = 0;
    int offsety = radius;
    int d = radius - 1;
    int status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderLine(global::renderer, x - offsety, y + offsetx, x + offsety, y + offsetx);
        status += SDL_RenderLine(global::renderer, x - offsetx, y + offsety, x + offsetx, y + offsety);
        status += SDL_RenderLine(global::renderer, x - offsetx, y - offsety, x + offsetx, y - offsety);
        status += SDL_RenderLine(global::renderer, x - offsety, y - offsetx, x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2 * offsetx) {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}

void Renderer::show() {
    SDL_RenderPresent(global::renderer);
}