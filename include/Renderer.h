#pragma once
#include <GL/freeglut.h>

class Mission;

class Renderer {
public:
    Renderer(Mission& mission);
    static void display();
    void drawCircle(float x, float y, float radius);
    void DrawSquare(float x, float y, float size);
// private:
    void drawInternal();
    Mission& mission;

    static Renderer* instance;
};
