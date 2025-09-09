#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

// Make your custom function here

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glColor3f(1, 1, 1);

    // Coordinate 
    glBegin(GL_LINES);
    glVertex2f(0.0, 500.0);
    glVertex2f(0.0, -500.0);
    glVertex2f(500.0, 0.0);
    glVertex2f(-500.0, 0.0);
    glEnd();

    glPointSize(4);

    // Call Your Function here

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
    glMatrixMode(GL_PROJECTION); //define scene by using projection
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0); // Set coordinate system

    glutDisplayFunc(display); // Register display callback
    glutMainLoop();           // Enter the GLUT event loop

    return 0;
}