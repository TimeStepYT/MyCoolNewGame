#include <SDL3/SDL.h>

class Renderer {

public:
    static void clear();
    static void setDrawColor(uint8_t r, uint8_t g, uint8_t b);
    static void drawRect(float x, float y, float w, float h, uint8_t r, uint8_t g, uint8_t b);
    static void drawCircle(float x, float y, float radius, uint8_t r, uint8_t g, uint8_t b);
    static void fillCircle(float x, float y, float radius, uint8_t r, uint8_t g, uint8_t b);
    static void show();
};