#pragma once
#include "Renderer.h"

class Mission {
public:
    Mission();
    void run();
    void updateLogic();
    void draw();
    void initGlut();

    float ballX = 5.0f;
    float ballSpeed = 0.1f;

    int steps = 0;

private:
    Renderer renderer;
};
