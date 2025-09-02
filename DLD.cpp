#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

void DLD(int x0, int y0, int xE, int yE)
{
    glBegin(GL_POINTS);

    // Swap points if x0 > xE to always draw left to right
    if (x0 > xE)
        swap(x0, xE), swap(y0, yE);

    float m = float(yE - y0) / (xE - x0); // slope
    float b = y0 - m * x0;                // y-intercept

    // Draw line pixel by pixel
    for (int x = x0; x <= xE; x++)
        glVertex2d(x, round(m * x + b)); // calculate y from line eqn

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glColor3f(1, 1, 1);

    glBegin(GL_LINES);
    glVertex2f(0.0, 100.0);
    glVertex2f(0.0, -100.0);
    glVertex2f(100.0, 0.0);
    glVertex2f(-100.0, 0.0);
    glEnd();

    glPointSize(2);
    // Hour Glass
    DLD(5, 5, 15, 5);
    DLD(5, 20, 15, 20);
    DLD(5, 5, 15, 20);
    DLD(15, 5, 5, 20);

    // Diamond
    // DDA(-10, -5, -15, -5);
    // DDA(-10, -5, -7, -7);
    // DDA(-15, -5, -18, -7);
    // DDA(-18, -7, -12, -10);
    // DDA(-7, -7, -12, -10);

    glFlush();
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500);                // Set window size
    glutInitWindowPosition(100, 100);            // Set window position
    glutCreateWindow("DDA");                     // Create window with title

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0); // Set coordinate system

    glutDisplayFunc(display); // Register display callback
    glutMainLoop();           // Enter the GLUT event loop

    return 0;
}