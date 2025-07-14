#include "Mission.h"
#include <iostream>
#include <thread>
#include <chrono>

void idleFunc() {
    glutPostRedisplay();  // solicita redibujar en el próximo ciclo
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float aspect = static_cast<float>(w) / static_cast<float>(h);

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w >= h) {
        glOrtho(0.0, 100.0 * aspect, 0.0, 100.0, -100.0, 100.0);
    } else {
        glOrtho(0.0, 100.0, 0.0, 100.0 / aspect, -100.0, 100.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


Mission::Mission() : renderer(*this) {}

void Mission::run() {
    glutMainLoop();
}

void Mission::updateLogic() {
    std::cout << "Avanzando simulación...\n";
    ballX += ballSpeed;

    if (ballX > 10.0f || ballX < 5.0f) {
        ballSpeed = -ballSpeed;
    }

    steps += 1;

    if (steps == 500) {
        renderer.drawInternal();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        glutLeaveMainLoop();
    }
}

void Mission::draw() {
    std::cout << "Dibujando estado...\n";
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void Mission::initGlut(){
    int argc = 1;
    char* argv[1] = { (char*)"app" };
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    if (true) {
        glutCreateWindow("ORCA");
    } else {
        glutCreateWindow("C-NAV");
    }

    glClearColor(0.0f, 0.3f, 0.5f, 1.0f);   // Fondo azul oscuro
    glutDisplayFunc(Renderer::display);
    glutIdleFunc(idleFunc);
    
    // glEnable(GL_DEPTH_TEST);  // habilita el depth test

    glutReshapeFunc(reshape);

    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
}
