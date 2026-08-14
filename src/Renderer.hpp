#pragma once
#include <SDL3/SDL.h>
#include "Color.hpp"

class Renderer {

public:
    static void clear();
    static void setDrawColor(Color color);
    static void drawRect(float x, float y, float w, float h, Color color);
    static void drawCircle(float x, float y, float radius, Color color);
    static void fillCircle(float x, float y, float radius, Color color);
    static void show();
};