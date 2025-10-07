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

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    float m = dy / (float)dx;

    int x = x0, y = y0;

    int xInc = (x1 >= x0) ? 1 : -1;
    int yInc = (y1 >= y0) ? 1 : -1;

    if (m < 1)
    {
        // Initial Decision Parameter
        int p = 2 * dy - dx;

        while (x <= x1)
        {
            plotPixel(x, y);
            x += xInc;
            if (p < 0)
            {
                p += 2 * dy;
            }
            else
            {
                y += yInc;
                p += 2 * dy - 2 * dx;
            }
        }
    }
    else
    {
        // Initial Decision Parameter
        int p = 2 * dx - dy;

        while (x <= x1)
        {
            plotPixel(x, y);
            y += yInc;
            if (p < 0)
            {
                p += 2 * dx;
            }
            else
            {
                x += xInc;
                p += 2 * dx - 2 * dy;
            }
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glColor3f(1, 1, 1);

    glBegin(GL_LINES);
    glVertex2f(0.0, 500.0);
    glVertex2f(0.0, -500.0);
    glVertex2f(500.0, 0.0);
    glVertex2f(-500.0, 0.0);
    glEnd();

    glPointSize(3);
    // Hour Glass
    BL(50, 50, 150, 50);
    BL(50, 200, 150, 200);
    BL(50, 50, 150, 200);
    BL(150, 50, 50, 200);

    glFlush();
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500);                // Set window size
    glutInitWindowPosition(100, 100);            // Set window position
    glutCreateWindow("Bresenham Algo.");         // Create window with title

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0); // Set coordinate system

    glutDisplayFunc(display); // Register display callback
    glutMainLoop();           // Enter the GLUT event loop

    return 0;
}