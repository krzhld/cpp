#include <GL/glut.h>
#include "game.h"

using namespace std;

Game g_game;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1, -1, 0);
    glScalef(2.0f / 800.0f, 2.0f / 600.0f, 1.0f);

    g_game.draw();

    glFlush();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    
}

void keyboard(unsigned char key, int x, int y) {

}

void initWindow(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Space invaders");
}

int main(int argc, char** argv) {
    initWindow(argc, argv);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
