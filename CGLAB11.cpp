#include <GL/freeglut.h>
#include <windows.h>

// Function to draw a single point
void drawPoint(float x, float y, float size, float r, float g, float b)
{
    glPointSize(size);
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    // Coordinate
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);

    // ---- Triangle ----
    // Line 1
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);
    // Line 2
    glVertex2f(0.2, 0.2);
    glVertex2f(0.5, 0.8);
    // Line 3
    glVertex2f(0.8, 0.2);
    glVertex2f(0.5, 0.8);

    // ---- Star ----
    // Line 1
    glVertex2f(-0.4, -0.45);
    glVertex2f(-0.9, -0.45);
    // Line 2
    glVertex2f(-0.4, -0.45);
    glVertex2f(-0.85, -0.85);
    // Line 3
    glVertex2f(-0.9, -0.45);
    glVertex2f(-0.5, -0.85);
    // Line 4
    glVertex2f(-0.85, -0.85);
    glVertex2f(-0.65, -0.2);
    // Line 5
    glVertex2f(-0.5, -0.85);
    glVertex2f(-0.65, -0.2);
    glEnd();

    // ---- Single Point ----
    // Coordinates and sizes
    float startX = -0.2f;
    float startY = 0.2f;
    float size = 10.0f;

    // RGB colors: Red, Green, Blue, Yellow, White
    float colors[5][3] = {
        {1.0f, 0.0f, 0.0f}, // Red
        {0.0f, 1.0f, 0.0f}, // Green
        {0.0f, 0.0f, 1.0f}, // Blue
        {1.0f, 1.0f, 0.0f}, // Yellow
        {1.0f, 1.0f, 1.0f}  // White
    };

    // Draw 5 points diagonally
    for (int i = 0; i < 5; i++)
    {
        float x = startX - 0.1f * i;
        float y = startY + 0.1f * i;
        drawPoint(x, y, size + 5.0f * i, colors[i][0], colors[i][1], colors[i][2]);
    }

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(450, 450);     // Window size
    glutInitWindowPosition(100, 100); // Window position
    glutCreateWindow("LAB 01");       // Window title
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutDisplayFunc(display); // Register display function
    glutMainLoop();           // Start the event loop
    return 0;
}
