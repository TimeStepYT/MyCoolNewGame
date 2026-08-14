#pragma once
#include "Color.hpp"

class Circle {
    Color m_color{};

    float m_radius = 0;
    float m_x = 0;
    float m_y = 0;

public:
    Circle(float x, float y, float radius);

    Circle* setColor(Color color);
    Circle* setPosition(float x, float y);
    Circle* setRadius(float radius);
    void drawFilled();
    void drawOutline();
};