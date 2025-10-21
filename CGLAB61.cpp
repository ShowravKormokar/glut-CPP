#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

// ==================== GLOBAL VARIABLES ====================
float triangle[3][2] = {
    {10, 10},
    {20, 10},
    {15, 20}};

float transformed[3][2]; // Store transformed triangle

// ==================== FUNCTIONS ====================

// Draw Triangle
void drawTriangle(float t[3][2])
{
    glBegin(GL_LINES);
    glVertex2f(t[0][0], t[0][1]);
    glVertex2f(t[1][0], t[1][1]);

    glVertex2f(t[1][0], t[1][1]);
    glVertex2f(t[2][0], t[2][1]);

    glVertex2f(t[2][0], t[2][1]);
    glVertex2f(t[0][0], t[0][1]);
    glEnd();
}

void copyMatrix(float a[3][2], float b[3][2])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = b[i][j];
}

// Translation
void translate(float tx, float ty)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] + tx;
        transformed[i][1] = triangle[i][1] + ty;
    }
    copyMatrix(triangle, transformed);
    glutPostRedisplay();
    glutPostRedisplay();
}

// Scaling
void scale(float sx, float sy)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] * sx;
        transformed[i][1] = triangle[i][1] * sy;
    }
    copyMatrix(triangle, transformed);
    glutPostRedisplay();
}

// Rotation
void rotateTriangle(float angle)
{
    float rad = angle * 3.14159 / 180.0;
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] * cos(rad) - triangle[i][1] * sin(rad);
        transformed[i][1] = triangle[i][0] * sin(rad) + triangle[i][1] * cos(rad);
    }
    copyMatrix(triangle, transformed);
    glutPostRedisplay();
}

// Reflection about X-axis
void reflectX()
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0];
        transformed[i][1] = -triangle[i][1];
    }
    copyMatrix(triangle, transformed);
    glutPostRedisplay();
}

// Reflection about Y-axis
void reflectY()
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = -triangle[i][0];
        transformed[i][1] = triangle[i][1];
    }
    copyMatrix(triangle, transformed);
    glutPostRedisplay();
}

// Shearing (about both axes)
void shear(float sh)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] + sh * triangle[i][1];
        transformed[i][1] = triangle[i][1] + sh * triangle[i][0];
    }
    copyMatrix(triangle, transformed);
    glutPostRedisplay();
}

// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    // Draw coordinate axes
    glBegin(GL_LINES);
    glVertex2f(0.0, 500.0);
    glVertex2f(0.0, -500.0);
    glVertex2f(500.0, 0.0);
    glVertex2f(-500.0, 0.0);
    glEnd();

    // Draw current triangle
    glColor3f(1, 1, 0);
    drawTriangle(triangle);

    // Draw transformed triangle (red)
    glColor3f(1, 0, 0);
    drawTriangle(triangle);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '1':
        cout << "Applying Translation...\n";
        translate(2, 3); // static values
        break;

    case '2':
        cout << "Applying Scaling...\n";
        scale(2, 2);     // first scaling
        scale(0.5, 0.5); // second scaling
        break;

    case '3':
        cout << "Applying Rotation...\n";
        rotateTriangle(45); // rotate 45°
        break;

    case '4':
        cout << "Applying Reflection about X-axis...\n";
        reflectX();
        break;

    case '5':
        cout << "Applying Reflection about Y-axis...\n";
        reflectY();
        break;

    case '6':
        cout << "Applying Shearing...\n";
        shear(2);
        break;

    case '0':
    case 27: // ESC key
        exit(0);
        break;

    default:
        cout << "Invalid key! Press 1-6, 0 to exit.\n";
        return;
    }

    glutPostRedisplay(); // refresh window to show transformed triangle
}

void printInstructions()
{
    cout << "\n** 2D TRANSFORMATION MENU **\n";
    cout << "1. Translation\n";
    cout << "2. Scaling\n";
    cout << "3. Rotation\n";
    cout << "4. Reflection about X-axis\n";
    cout << "5. Reflection about Y-axis\n";
    cout << "6. Shearing\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main(int argc, char **argv)
{
    // Now initialize GLUT and show window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Transformations - Triangle");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50);

    printInstructions();

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    glutMainLoop(); // Start rendering only after transformation is selected

    return 0;
}