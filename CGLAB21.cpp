#include <GL/glut.h>
#include <windows.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Draw Coordinate Axes
    glColor3f(1, 1, 1); // White
    glBegin(GL_LINES);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);

    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    glPointSize(5);

    // Draw "A" with Blue color
    glColor3f(0, 0, 1); // Blue
    glBegin(GL_POINTS);
    // Left slant of A
    for (float i = 0.1; i <= 0.5; i += 0.001)
    {
        glVertex2f(i, i);
    }
    // Right slant of A
    for (float i = 0.5; i <= 0.9; i += 0.001)
    {
        glVertex2f(i, 1 - i);
    }
    // Middle bar of A
    for (float i = 0.3; i <= 0.7; i += 0.01)
    {
        glVertex2f(i, 0.3);
    }
    glEnd();

    // Draw "E" with Green color
    glColor3f(0, 1, 0); // Green
    glBegin(GL_POINTS);
    // Horizontal bars of E
    for (float k = -0.2; k >= -0.9; k -= 0.3)
    {
        for (float i = -0.3; i >= -0.7; i -= 0.01)
        {
            glVertex2f(i, k);
        }
    }
    // Vertical bar of E
    for (float i = -0.2; i >= -0.8; i -= 0.01)
    {
        glVertex2f(-0.7, i);
    }
    glEnd();

    glFlush();
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500);                // Set window size
    glutInitWindowPosition(100, 100);            // Set window position
    glutCreateWindow("Draw A and E");            // Create window with title

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glOrtho(-1, 1, -1, 1, -1, 1);         // Set coordinate system

    glutDisplayFunc(display); // Register display callback
    glutMainLoop();           // Enter the GLUT event loop

    return 0;
}
