#include <GL/glut.h>

// Initial square position
float x_pos = -400; // Start from left
float y_pos = 0;    // Y fixed
float speed = 2;    // Move speed (pixels per frame)

// Function to draw the square
void drawSquare(float x, float y)
{
    glBegin(GL_QUADS); // Use GL_QUADS
    glVertex2f(x, y);
    glVertex2f(x + 100, y);
    glVertex2f(x + 100, y + 100);
    glVertex2f(x, y + 100);
    glEnd();
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0); // Yellow square
    drawSquare(x_pos, y_pos);

    glFlush();
}

// Timer function for animation
void update(int value)
{
    // Move square to the right until it reaches edge (window width = 500)
    if (x_pos + 100 < 500)
        x_pos += speed;

    glutPostRedisplay();          // Redraw the screen
    glutTimerFunc(16, update, 0); // Call again after ~16 ms (≈60 FPS)
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square Translation - Left to Right");

    glClearColor(0, 0, 0, 1); // Background black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -250, 250); // Coordinate system

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0); // Start the timer

    glutMainLoop();
    return 0;
}