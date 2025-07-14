// #include "glut_renderer.cpp"
#include "glut_renderer.h"

// void updateLogic() {
//     step += 1;
//     if (step>= limitStep){
//         glutLeaveMainLoop();
//     }
//     // Actualiza la posición del círculo
//     ballX += ballSpeed;

//     if (ballX > 3.0f || ballX < 2.0f) {
//         ballSpeed = -ballSpeed;  // rebote simple
//     }
// }

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    prepareRenderer();
    // glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // glutInitWindowSize(windowWidth, windowHeight);
    // if(true){
    //     glutCreateWindow("ORCA");
    // }else{
    //     glutCreateWindow("C-NAV");
    // }
    
    // glClearColor(0.0f, 0.3f, 0.5f, 1.0f);   // Fondo azul oscuro
    // // glEnable(GL_DEPTH_TEST);  // habilita el depth test

    // glutDisplayFunc(display);
    // // glutReshapeFunc(reshape);
    // glutIdleFunc(idleFunc);

    // glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
    glutMainLoop();

    return 0;
}
