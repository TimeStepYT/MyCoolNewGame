#include "Circle.hpp"
#include "Renderer.hpp"

Circle::Circle(float x, float y, float radius) {
    this->m_x = x;
    this->m_y = y;
    this->m_radius = radius;
}

Circle* Circle::setColor(Color color) {
    this->m_color = color;

    return this;
}

Circle* Circle::setPosition(float x, float y) {
    this->m_x = x;
    this->m_y = y;

    return this;
}

Circle* Circle::setRadius(float radius) {
    this->m_radius = radius;

    return this;
}

void Circle::drawFilled() {
    Renderer::fillCircle(this->m_x, this->m_y, this->m_radius, this->m_color);
}

void Circle::drawOutline() {
    Renderer::drawCircle(this->m_x, this->m_y, this->m_radius, this->m_color);
}