// Performing 2D transformations
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

// ==================== GLOBAL VARIABLES ====================
float triangle[3][2] = {
    {100, 100},
    {200, 100},
    {150, 200}};

float transformed[3][2]; // Store transformed triangle

// Draw Triangle
void drawTriangle(float t[3][2])
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
        glVertex2f(t[i][0], t[i][1]);
    glEnd();
}

void copyMatrix(float a[3][2], float b[3][2])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = b[i][j];
}

// Translation
void translate(float tx, float ty)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] + tx; // newX = oldX + tx
        transformed[i][1] = triangle[i][1] + ty; // newY = oldY + ty
    }

    copyMatrix(triangle, transformed);
}

// Scaling
void scale(float sx, float sy)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] * sx; // newX = oldX * sx
        transformed[i][1] = triangle[i][1] * sy; // newY = oldY * sy
    }

    copyMatrix(triangle, transformed);
}

// Rotation (counterclockwise)
void rotate(float angle)
{
    float rad = angle * 3.14159 / 180.0;
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] * (cos(rad)) - triangle[i][1] * sin(rad);
        transformed[i][1] = triangle[i][0] * sin(rad) + triangle[i][1] * cos(rad);
    }

    copyMatrix(triangle, transformed);
}

// Reflection about X-axis
void reflectX()
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0];  // x' = x
        transformed[i][1] = -triangle[i][1]; // y' = -y
    }

    copyMatrix(triangle, transformed);
}

// Reflection about Y-axis
void reflectY()
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = -triangle[i][0]; // x' = -x
        transformed[i][1] = triangle[i][1];  // y' = y
    }

    copyMatrix(triangle, transformed);
}

// Shearing
void shear(float shr)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] + shr * triangle[i][1]; // x-shear
        transformed[i][1] = triangle[i][1] + shr * triangle[i][0]; // y-shear
    }

    copyMatrix(triangle, transformed);
}

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

    glPointSize(4);

    // Draw original triangle (yellow)
    glColor3f(1, 1, 0);
    drawTriangle(triangle);

    // Perform transformations (Call All function here)
    translate(100, 50);
    // scale(1.5, 1.5);
    // rotate(180);
    // shear(0.3, 0.1);

    // Draw transformed triangle (red)
    glColor3f(1, 0, 0);
    drawTriangle(triangle);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Transformations - Triangle");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}