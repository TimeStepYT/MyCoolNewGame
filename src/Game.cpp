#include "Game.hpp"
#include "Renderer.hpp"

void Game::update() {
    Renderer::clear();
    
    Renderer::drawRect(400, 200, 100, 200, 255, 0, 0);
    Renderer::fillCircle(400, 400, 50, 255, 0, 0);
    Renderer::fillCircle(500, 400, 50, 255, 0, 0);
    Renderer::setDrawColor(30, 30, 30);

    Renderer::show();
}