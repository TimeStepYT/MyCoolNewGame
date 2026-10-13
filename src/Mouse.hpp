#pragma once

#include <vector>
#include "Position.hpp"

enum class MouseButtonID {
        LEFT = 1,
        MIDDLE = 2,
        RIGHT = 3,
        BACK = 4,
        FORTH = 5
    };

class Mouse {
    std::vector<MouseButtonID> m_buttonsDown;
    std::vector<MouseButtonID> m_freshButtonsDown;
    Position m_pos{};
    
public:
    Mouse() = default;
    Mouse(Mouse const&) = delete;
    static Mouse& get();

    Position getPosition() const;
    void setPosition(Position pos);
    void setClicked(MouseButtonID buttonID);
    void setNotClicked(MouseButtonID buttonID);
    bool isDown(MouseButtonID buttonID = MouseButtonID::LEFT) const;
    bool isClicked(MouseButtonID buttonID = MouseButtonID::LEFT) const;
    void update();
};