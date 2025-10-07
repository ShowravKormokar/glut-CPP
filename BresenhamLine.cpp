#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void plotPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void BL(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int x = x0;
    int y = y0;

    int sx = (x1 > x0) ? 1 : -1;
    int sy = (y1 > y0) ? 1 : -1;

    bool steep = dy > dx;

    if (steep)
        swap(dx, dy);

    int p = 2 * dy - dx;

    for (int i = 0; i <= dx; i++)
    {
        plotPixel(x, y);
        if (p >= 0)
        {
            if (steep)
                x += sx;
            else
                y += sy;
            p -= 2 * dx;
        }

        if (steep)
            y += sy;
        else
            x += sx;

        p += 2 * dy;
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

    // Letter S
    BL(100, 200, 200, 200); // Top horizontal
    BL(100, 200, 100, 150); // Left vertical (upper)
    BL(100, 150, 200, 150); // Middle horizontal
    BL(200, 150, 200, 100); // Right vertical (lower)
    BL(200, 100, 100, 100); // Bottom horizontal

    glFlush();
}

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
