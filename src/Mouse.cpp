#include "Mouse.hpp"

#include <algorithm>

template <class T>
bool contains(std::vector<T> list, T item) {
    return std::find(list.begin(), list.end(), item) != list.end();
}

Mouse& Mouse::get() {
    static Mouse instance{};
    return instance;
}

void Mouse::setPosition(Position pos) {
    this->m_pos = pos;
}

Position Mouse::getPosition() const {
    return this->m_pos;
}

void Mouse::setClicked(MouseButtonID buttonID) {
    if (contains(this->m_buttonsDown, buttonID)) {
        return;
    }
    this->m_buttonsDown.push_back(buttonID);
    this->m_freshButtonsDown.push_back(buttonID);
}

void Mouse::setNotClicked(MouseButtonID buttonID) {
    if (!contains(this->m_buttonsDown, buttonID)) {
        return;
    }
    auto it = std::find(this->m_buttonsDown.begin(), this->m_buttonsDown.end(), buttonID);
    this->m_buttonsDown.erase(it);
}

bool Mouse::isDown(MouseButtonID buttonID) const {
    return contains(this->m_buttonsDown, buttonID);
}

bool Mouse::isClicked(MouseButtonID buttonID) const {
    return contains(this->m_freshButtonsDown, buttonID);
}

void Mouse::update() {
    this->m_freshButtonsDown.clear();
}