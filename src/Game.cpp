#include "Game.hpp"
#include "Circle.hpp"
#include "Renderer.hpp"
#include "Mouse.hpp"

Game::Game() {
    this->init();
}

Game::~Game() {
    delete this->m_cursorCircle;
}

void Game::init() {
    this->m_cursorCircle = new Circle{0, 0, 10};
    this->m_cursorCircle->setColor(Color{0, 255, 0});

}

void Game::update() {
    Renderer::clear();

    Mouse& mouse = Mouse::get();
    Position const mousePos = mouse.getPosition();

    this->m_cursorCircle->setPosition(mousePos.x, mousePos.y);
    this->m_cursorCircle->drawOutline();

    mouse.update();
    Renderer::show();
}