// Direct circle drawing algorithm
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

void DCA(int r)
{
    glColor3f(0, 0, 1); // Color Blue
    glBegin(GL_POINTS);
    int x = 0;
    while (x <= r)
    {
        int y = sqrt(pow(r, 2) - pow(x, 2));
        glVertex2i(x, y);
        glVertex2i(x, -y);
        glVertex2i(-x, -y);
        glVertex2i(-x, y);
        x++;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    // Coordinate
    glBegin(GL_LINES);
    glVertex2f(0.0, 500.0);
    glVertex2f(0.0, -500.0);
    glVertex2f(500.0, 0.0);
    glVertex2f(-500.0, 0.0);
    glEnd();

    glPointSize(4);

    DCA(200); // Call The Function

    glFlush();
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DCA");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}