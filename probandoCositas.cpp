// main.cpp
#include <GL/freeglut.h>
#include <iostream>

// Adelantar declaración
class Mission;

class Renderer {
public:
    Renderer(Mission& mission) : mission(mission) {
        Renderer::instance = this;  // guardar instancia activa
    }

    static void display();  // función que GLUT puede llamar

private:
    void drawInternal();    // lógica real de dibujado
    Mission& mission;

    static Renderer* instance;
};

Renderer* Renderer::instance = nullptr;

class Mission {
public:
    Mission() : renderer(*this) {}

    void run() {
        int argc = 1;
        char* argv[1] = { (char*)"app" };
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
        glutInitWindowSize(800, 600);
        glutCreateWindow("Simulación");

        glutDisplayFunc(Renderer::display);
        glutIdleFunc(Renderer::display);  // solo para el ejemplo

        glutMainLoop();
    }

    void step() {
        std::cout << "Avanzando simulación...\n";
    }

    void draw() {
        std::cout << "Dibujando estado...\n";
        glClear(GL_COLOR_BUFFER_BIT);
        // Aquí iría la lógica de renderizado real con OpenGL
        glutSwapBuffers();
    }

private:
    Renderer renderer;
};

// --- Métodos del renderer ---

void Renderer::display() {
    if (instance) {
        instance->mission.step();         // Avanzar simulación
        instance->drawInternal();         // Dibujar
    }
}

void Renderer::drawInternal() {
    mission.draw();
}

// --- Main ---

int main() {
    Mission mission;
    mission.run();
    return 0;
}
