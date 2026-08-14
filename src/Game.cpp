#include "Game.hpp"
#include "Circle.hpp"
#include "Renderer.hpp"
#include "Mouse.hpp"

void Game::update() {
    Renderer::clear();
    
    Renderer::drawRect(400, 200, 100, 200, Color{ 255, 0, 0});
    
    Circle ball1{400, 400, 50};
    Circle ball2{500, 400, 50};
    ball1.setColor(Color{ 255, 0, 0})->drawFilled();
    ball2.setColor(Color{255, 0, 0})->drawFilled();

    Mouse::get().update();

    Renderer::show();
}