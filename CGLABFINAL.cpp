// Mid-point Circle Drawing Algorithm - With User Input
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

// Global variables to store user input
int xc, yc;

void MCA(int xc, int yc, int r)
{
    glColor3f(0, 1, 1); // Cyan color
    glBegin(GL_POINTS);

    int x = 0, y = r;
    int p = 1 - r;

    while (x < y)
    {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc - y, yc - x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc - x, yc + y);

        if (p >= 0)
        {
            p += ((2 * x) - (2 * y)) + 5;
            x++, y--;
        }
        else
        {
            p += (2 * x) + 3;
            x++;
        }
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    glBegin(GL_LINES);

    glVertex2f(0.0, 200.0);
    glVertex2f(0.0, -200.0);
    glVertex2f(200.0, 0.0);
    glVertex2f(-200.0, 0.0);

    glEnd();

    glPointSize(4);

    // Draw the circle using user inputs
    MCA(xc, yc, 80); // Fixed radius of 80

    glFlush();
}

int main(int argc, char **argv)
{
    cout << "Enter circle center (xc yc): ";
    cin >> xc >> yc;

    // GLUT initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Algorithm - User Input");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
