#include <iostream>
#include <GL/freeglut.h>
#include <utility>

float ballX = 0.0f;
float ballSpeed = 0.01f;

float cellSize = 0.1f;
float z_depth = -0.0f;

// std::pair<float, float> origin = std::make_pair(0.0f, 0.0f); // origen de coordenadas
std::pair<float, float> origin = std::make_pair(-0.8f, -0.8f); // origen de coordenadas

void transformCoordinates(float x, float y) {
    glTranslatef(origin.first + x*cellSize, origin.second + y*cellSize, z_depth);
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float aspect = (float)w / (float)h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void updateLogic() {
    // Actualiza la posición del círculo
    ballX += ballSpeed;
    if (ballX > 1.0f || ballX < -1.0f) {
        ballSpeed = -ballSpeed;  // rebote simple
    }
}

void idleFunc() {
    updateLogic();
    glutPostRedisplay();  // Solicita redibujar la ventana
}

void renderBitmapString(float x, float y, void* font, const char* string) {
    glPushMatrix();
    transformCoordinates(x, y);

    glColor3f(1.0f, 1.0f, 1.0f);  // blanco
    glRasterPos2f(0.0f, 0.0f);  // Establece la posición donde comienza el texto
    for (const char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }

    glPopMatrix();
}

void drawSquare(float x, float y, float size) {
    glPushMatrix();

    // glTranslatef(x, y, -2.0f);
    transformCoordinates(x, y);
    glColor3f(1.0f, 0.0f, 0.0f);  // verde

    glBegin(GL_QUADS);
        glVertex3f(-size / 2, -size / 2, 0.0f);  // esquina inferior izquierda
        glVertex3f(size / 2, -size / 2, 0.0f);   // esquina inferior derecha
        glVertex3f(size / 2, size / 2, 0.0f);    // esquina superior derecha
        glVertex3f(-size / 2, size / 2, 0.0f);   // esquina superior izquierda
    glEnd();

    glPopMatrix();
}

void drawCircle(float x, float y, float radius, float r, float g, float b, float a) {
    glPushMatrix();

    transformCoordinates(x, y);
    glColor4f(r, g, b, a);  
    glutSolidSphere(radius, 20, 20);

    glPopMatrix();
}

void drawAgent(float x, float y, float radius = cellSize/2, float sightRadius= cellSize){
    drawCircle(x, y, sightRadius, 0.0f, 0.0f, 0.0f, 0.5f);
    drawCircle(x, y, radius, 1.0f, 1.0f, 0.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glEnable(GL_BLEND);  // Activar el blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  // Configurar el blending

    // Mueve la cámara hacia atrás (si quieres)
    // glTranslatef(0.0f, 0.0f, -2.0f);  // opcional, pero redundante si ya colocas la esfera en -2.0

    drawSquare(0.0f, 0.0f, cellSize);
    drawAgent(ballX, 0.0f);
    drawAgent(ballX, 1.0f);
    drawAgent(ballX, 2.0f);
    renderBitmapString(ballX, 0.0f, GLUT_BITMAP_HELVETICA_18, "¡Hola, mundo!");
    renderBitmapString(ballX, 1.0f, GLUT_BITMAP_HELVETICA_18, "¡Hola, mundo!");
    renderBitmapString(ballX, 2.0f, GLUT_BITMAP_HELVETICA_18, "¡Hola, mundo!");

    
    glDisable(GL_BLEND);  // Desactivar el blending

    glutSwapBuffers(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    if(true){
        glutCreateWindow("ORCA");
    }else{
        glutCreateWindow("C-NAV");
    }
    
    glClearColor(0.0f, 0.3f, 0.5f, 1.0f);   // Fondo azul oscuro
    // glEnable(GL_DEPTH_TEST);  // habilita el depth test

    glutDisplayFunc(display);
    // glutReshapeFunc(reshape);
    glutIdleFunc(idleFunc);

    glutMainLoop();
    return 0;
}
