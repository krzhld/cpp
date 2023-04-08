#include "window.h"

using namespace std;

Window window;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1, -1, 0);
    glScalef(2.0f / window.getRect().getSizeX(), 2.0f / window.getRect().getSizeY(), 1.0f);

    window.draw();

    glFlush();
    glutSwapBuffers();
}

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

void init(void) {
    glClearColor(255.0, 255.0, 255.0, 0.0);
}

void mouseButton(int button, int state, int x, int y) {
    if (state == GLUT_LEFT_BUTTON) {
        y = window.getRect().getSizeY() - y; // because of left-handed system
        std::cout << x << " " << y << std::endl;
        if (window.clickHandler(x, y))
            display();
    }
}

void initWindow(int argc, char** argv) {
    Rectangle window_rect = window.getRect();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(window_rect.getX(), window_rect.getY());
    glutInitWindowSize(window_rect.getSizeX(), window_rect.getSizeY());
    glutCreateWindow(window.getName().c_str());
}

int main(int argc, char** argv) {
    ifstream input_file_stream("menu.txt");
    window = Window(input_file_stream);
    initWindow(argc, argv);

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseButton);
    glutMainLoop();
}

/*
+ передавать большие объекты по ссылке
+ конструктор меню попробовать сделать от потока файла
+ сеттеры убрать
+ избавиться от структурного стиля кода
*/
