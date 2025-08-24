#include <GL/glut.h>
#include <windows.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glColor3f(1, 1, 1);
    glBegin(GL_LINES); // Start drawing lines
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);

    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, -0.0f);

    glEnd();

    glPointSize(5);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    for (float i = 0.3; i <= 0.7; i += 0.01)
    {
        glVertex2f(i, 0.3);
    }

    for (float i = 0.1; i <= 0.5; i += 0.001)
    {
        glVertex2f(i, i);
    }

    for (float i = 0.5; i <= 0.9; i += 0.001)
    {
        glVertex2f(i, 1 - i);
    }

    // E
    for (float k = -0.2; k >= -0.9; k -= 0.3)
    {
        for (float i = -0.3; i >= -0.7; i -= 0.01)
        {
            glVertex2f(i, k);
        }
    }

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
    glutCreateWindow("Simple Line");             // Create window with title

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glColor3f(1.0f, 1.0f, 1.0f);          // Set line color to white
    glOrtho(-1, 1, -1, 1, -1, 1);         // Set coordinate system

    glutDisplayFunc(display); // Register display callback
    glutMainLoop();           // Enter the GLUT event loop

    return 0;
}