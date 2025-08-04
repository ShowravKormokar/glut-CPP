#include <GL/freeglut.h>
#include <windows.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    // Coordinate
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);

    // ---- Triangle ----
    // Line 1
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);
    // Line 2
    glVertex2f(0.2, 0.2);
    glVertex2f(0.5, 0.8);
    // Line 3
    glVertex2f(0.8, 0.2);
    glVertex2f(0.5, 0.8);

    // ---- Star ----
    // Line 1
    glVertex2f(-0.4, -0.45);
    glVertex2f(-0.9, -0.45);
    // Line 2
    glVertex2f(-0.4, -0.45);
    glVertex2f(-0.85, -0.85);
    // Line 3
    glVertex2f(-0.9, -0.45);
    glVertex2f(-0.5, -0.85);
    // Line 4
    glVertex2f(-0.85, -0.85);
    glVertex2f(-0.65, -0.2);
    // Line 5
    glVertex2f(-0.5, -0.85);
    glVertex2f(-0.65, -0.2);
    glEnd();

    // ---- Points ----
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.2, 0.2);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.3, 0.3);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.4, 0.4);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, 0.5);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.6, 0.6);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(450, 450);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("LAB 01");
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
