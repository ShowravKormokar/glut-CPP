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

// Translation
void translate(float tx, float ty)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] + tx;
        transformed[i][1] = triangle[i][1] + ty;
    }
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
    glutPostRedisplay();
}

// Shearing about X-axis
void shearX(float shx)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] + shx * triangle[i][1];
        transformed[i][1] = triangle[i][1]; // Y remains unchanged
    }
}

// Shearing about Y-axis
void shearY(float shy)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0]; // X remains unchanged
        transformed[i][1] = triangle[i][1] + shy * triangle[i][0];
    }
}

// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    // Draw coordinate axes
    glBegin(GL_LINES);
    glVertex2f(0.0, 100.0);
    glVertex2f(0.0, -100.0);
    glVertex2f(100.0, 0.0);
    glVertex2f(-100.0, 0.0);
    glEnd();

    // Draw current triangle
    glColor3f(1, 1, 0);
    drawTriangle(triangle);

    // Draw transformed triangle (red)
    glColor3f(1, 0, 0);
    drawTriangle(transformed);

    glFlush();
}

// ==================== MAIN ====================
int main(int argc, char **argv)
{
    // Now initialize GLUT and show window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Transformations - Triangle");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);

    // Interactive menu BEFORE opening GLUT
    int choice;
    cout << "\n** 2D TRANSFORMATION MENU **\n";
    cout << "1. Translation\n";
    cout << "2. Scaling\n";
    cout << "3. Rotation\n";
    cout << "4. Reflection about X-axis\n";
    cout << "5. Reflection about Y-axis\n";
    cout << "6. Shearing X\n";
    cout << "7. Shearing Y\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 0)
        return 0;

    // Apply chosen transformation with static values
    switch (choice)
    {
    case 1:
        cout << "Applying Translation...\n";
        translate(2, 3);
        break;

    case 2:
        cout << "Applying Scaling...\n";
        scale(2, 2);
        scale(0.5, 0.5);
        break;

    case 3:
        cout << "Applying Rotation...\n";
        rotateTriangle(45);
        break;

    case 4:
        cout << "Applying Reflection about X-axis...\n";
        reflectX();
        break;

    case 5:
        cout << "Applying Reflection about Y-axis...\n";
        reflectY();
        break;

    case 6:
        cout << "Applying Shearing...\n";
        shearX(2);
        break;

    case 7:
        cout << "Applying Shearing...\n";
        shearY(2);
        break;

    default:
        cout << "Invalid choice! Exiting...\n";
        return 0;
    }
    glutDisplayFunc(display);
    glutMainLoop(); // Start rendering only after transformation is selected

    return 0;
}