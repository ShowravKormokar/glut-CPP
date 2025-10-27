#include <GL/glut.h>

// Initial square position
float x_pos = -400;  // Start from left
float y_pos = 0;     // Y fixed
float speed = 2;     // Move speed (pixels per frame)
bool moving = false; // Flag: move only when key is pressed

// Function to draw the square
void drawSquare(float x, float y)
{
    glBegin(GL_POLYGON);
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
    if (moving && x_pos + 100 < 500)
        x_pos += speed; // Move right only if moving

    if (x_pos + 100 == 500)
        exit(0);

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Repeat ~60 FPS
}

// Key press event
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        moving = true; // Start moving when key is pressed
}

// Key release event
void specialKeysUp(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        moving = false; // Stop moving when key is released
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square Move with Arrow Key");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutSpecialFunc(specialKeys);     // Key press
    glutSpecialUpFunc(specialKeysUp); // Key release

    glutMainLoop();
    return 0;
}
