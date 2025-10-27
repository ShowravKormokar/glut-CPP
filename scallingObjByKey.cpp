#include <GL/glut.h>

float x_pos = 0;          // Square position X
float y_pos = 0;          // Square position Y
float size = 0.2f;        // Initial square half-size
float scaleSpeed = 0.01f; // Scaling speed
int scaling = 0;          // 1=up, -1=down, 0=stop

// Draw square at current position and size
void drawSquare()
{
    glBegin(GL_POLYGON);
    glVertex2f(x_pos - size, y_pos - size);
    glVertex2f(x_pos + size, y_pos - size);
    glVertex2f(x_pos + size, y_pos + size);
    glVertex2f(x_pos - size, y_pos + size);
    glEnd();
}

// Display callback
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0); // Green square
    drawSquare();
    glFlush();
}

// Timer function for scaling
void update(int value)
{
    if (scaling == 1 && size < 0.9f) // scale up
        size += scaleSpeed;
    else if (scaling == -1 && size > 0.05f) // scale down
        size -= scaleSpeed;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}

// Key press
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'u' || key == 'U')
        scaling = 1; // scale up
    else if (key == 'd' || key == 'D')
        scaling = -1; // scale down
}

// Key release
void keyboardUp(unsigned char key, int x, int y)
{
    if (key == 'u' || key == 'U' || key == 'd' || key == 'D')
        scaling = 0; // stop scaling
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scaling Square - Press 'u' or 'd'");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
