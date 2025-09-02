#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

// Digital Differential Analyzer (DDA)
void DDA(int x0, int y0, int xE, int yE)
{
    glBegin(GL_POINTS);
    float m = float(yE - y0) / (xE - x0); // slope

    if (abs(m) < 1)
    {
        if (x0 > xE) // Swap points if x0 > xE to always draw left to right
            swap(x0, xE), swap(y0, yE);
        float y = y0;
        for (int x = x0; x <= xE; x++, y += m)
            glVertex2d(x, round(y));
    }
    else
    {
        if (y0 > yE)
            swap(x0, xE), swap(y0, yE);
        float x = x0;
        for (int y = y0; y <= yE; y++, x += 1 / m)
        {
            glVertex2d(round(x), y);
        }
    }
    glEnd();
}

// Direct Line Drawing Algorithm (DLD)
void DLD(int x0, int y0, int xE, int yE)
{
    glBegin(GL_POINTS);

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

    glPointSize(4);
    // Draw Hour Glass using DDA
    DDA(5, 5, 20, 5);
    DDA(5, 25, 20, 25);
    DDA(5, 5, 20, 25);
    DDA(20, 5, 5, 25);

    // Draw Triangle using DLD
    DLD(-10, -25, -30, -25);
    DLD(-10, -25, -20, -15);
    DLD(-30, -25, -20, -15);

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
    gluOrtho2D(-40.0, 40.0, -40.0, 40.0); // Set coordinate system

    glutDisplayFunc(display); // Register display callback
    glutMainLoop();           // Enter the GLUT event loop

    return 0;
}