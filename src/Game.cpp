#include "Game.hpp"
#include "Circle.hpp"
#include "Renderer.hpp"

void Game::update() {
    Renderer::clear();
    
    Renderer::drawRect(400, 200, 100, 200, {255, 0, 0});
    
    Circle ball1{400, 400, 50};
    Circle ball2{500, 400, 50};
    ball1.setColor({ 255, 0, 0 })->drawFilled();
    ball2.setColor({255, 0, 0})->drawFilled();

    Renderer::show();
}