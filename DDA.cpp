#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

void DDA(int x0, int y0, int xE, int yE)
{
    glBegin(GL_POINTS);
    float m = float(yE - y0) / (xE - x0);

    if (abs(m) < 1)
    {
        if (x0 > xE)
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
            // cout << "x= " << x << endl;
            // cout << "y= " << y << endl;
            glVertex2d(round(x), y);
        }
    }
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
    // Draw Hour Glass using DDA
    DDA(5, 5, 15, 5);
    DDA(5, 20, 15, 20);
    DDA(5, 5, 15, 20);
    DDA(15, 5, 5, 20);

    // Draw Triangle using DLD
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