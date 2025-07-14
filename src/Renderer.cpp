#include "Renderer.h"
#include "Mission.h"
#include <iostream>

float cellSize = 20.0f;

Renderer* Renderer::instance = nullptr;

Renderer::Renderer(Mission& mission) : mission(mission) {
    Renderer::instance = this;
}

void Renderer::display() {
    if (instance) {
        instance->mission.updateLogic();
        instance->drawInternal();
        glutSwapBuffers();
    }
}

void Renderer::drawInternal() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        // limpia la pantalla
    glLoadIdentity();

    // DrawSquare(10.0f, 10.0f, cellSize);  // Cuadrado de 20x20 unidades
    // float a = cellSize/2;
    // drawCircle(10.0f + a, 10.0f + a, a);

    DrawSquare(mission.ballX*3, 50.0, cellSize);

    // glutSwapBuffers(); comentado porque se encuentra en display()

}

void Renderer::drawCircle(float x, float y, float radius) {
    glPushMatrix();

    // glTranslatef(origin.first + x*cellSize, origin.second + y*cellSize, z_depth);
    glTranslatef(x, y, -20.0f);  // Aleja la esfera para que la cámara la vea

    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidSphere(radius, 20, 20);
    

    glPopMatrix();
}

void Renderer::DrawSquare(float x, float y, float size) {
    glPushMatrix();

    glTranslatef(x, y, -20.0f);  // Aleja la esfera para que la cámara la vea
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(size, 0.0f, 0.0f);
        glVertex3f(size, size, 0.0f);
        glVertex3f(0.0f, size, 0.0f);
    glEnd();

    glPopMatrix();
}

