#pragma once

#include "Circle.hpp"

class Game {
private:
    Circle* m_cursorCircle = nullptr;

    void init();

public:
    Game();
    ~Game();
    void update();
};