#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

void plotPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void BL(int x0, int y0, int x1, int y1)
{
    if (x0 > x1 || y0 > y1)
        swap(x0, x1), swap(y0, y1);

    int dx = x1 - x0;
    int dy = y1 - y0;
    int x = x0, y = y0;
    int p = 2 * dy - dx;

    while (x <= x1)
    {
        plotPixel(x, y);
        x++;
        if (p < 0)
        {
            p += 2 * dy;
        }
        else
        {
            y++;
            p += 2 * dy - 2 * dx;
        }
    }
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
    BL(5, 5, 15, 5);
    BL(5, 20, 15, 20);
    BL(5, 5, 15, 20);
    BL(15, 5, 5, 20);

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