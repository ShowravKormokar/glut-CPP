// Draw diagonal line
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

// Diagonal Line Algo
void DL(int x0, int y0, int x1, int y1)
{
    float m = (y1 - y0) / (float)(x1 - x0);
    if (m > 0)
    {
        if (x0 <= x1 && y0 <= y1)
        {
            int x = x0;
            int y = y0;

            while (x <= x1)
            {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
                x += 1;
                y += 1;
            }
        }
    }
    else if (m < 0)
    {
        if (x0 <= x1 && y0 >= y1)
        {
            int x = x0;
            int y = y0;

            while (x <= x1)
            {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
                x += 1;
                y -= 1;
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

    glPointSize(4);

    // Diagonal Line
    DL(100, 300, 300, 100); // for m=-1
    DL(100, 100, 300, 300); // for m==1

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
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0); // Set coordinate system

    glutDisplayFunc(display); // Register display callback
    glutMainLoop();           // Enter the GLUT event loop

    return 0;
}