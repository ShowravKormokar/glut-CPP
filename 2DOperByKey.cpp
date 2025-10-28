#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

float triangle[3][2] = {
    {10, 10},
    {20, 10},
    {15, 20}}; // Original triangle

float transformed[3][2]; // Store transformed triangle
int step = 0;            // Current operation step

// Draw Triangle
void drawTriangle(float t[3][2])
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
        glVertex2f(t[i][0], t[i][1]);
    glEnd();
}

// ======== Transformations ======== //
void translate(float tx, float ty)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] + tx;
        transformed[i][1] = triangle[i][1] + ty;
    }
}

void scale(float sx, float sy)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] * sx;
        transformed[i][1] = triangle[i][1] * sy;
    }
}

void rotateTriangle(float angle)
{
    float rad = angle * 3.1416 / 180.0;
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] * cos(rad) - triangle[i][1] * sin(rad);
        transformed[i][1] = triangle[i][0] * sin(rad) + triangle[i][1] * cos(rad);
    }
}

void reflectX()
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0];
        transformed[i][1] = -triangle[i][1];
    }
}

void reflectY()
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = -triangle[i][0];
        transformed[i][1] = triangle[i][1];
    }
}

void shearX(float shx)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0] + shx * triangle[i][1];
        transformed[i][1] = triangle[i][1];
    }
}

void shearY(float shy)
{
    for (int i = 0; i < 3; i++)
    {
        transformed[i][0] = triangle[i][0];
        transformed[i][1] = triangle[i][1] + shy * triangle[i][0];
    }
}

// ======== Display ======== //
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw coordinate axes
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_LINES);
    glVertex2f(0, 100);
    glVertex2f(0, -100);
    glVertex2f(100, 0);
    glVertex2f(-100, 0);
    glEnd();

    // Draw original triangle (yellow)
    glColor3f(1, 1, 0);
    drawTriangle(triangle);

    // Draw transformed triangle (red)
    glColor3f(1, 0, 0);
    drawTriangle(transformed);

    glFlush();
}

// ======== Key Control ======== //
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
    {
        step++;

        switch (step)
        {
        case 1:
            cout << "Showing Translation...\n";
            translate(20, 30);
            break;
        case 2:
            cout << "Showing Scaling (0.5x)...\n";
            scale(0.5, 0.5);
            break;
        case 3:
            cout << "Showing Scaling (2x)...\n";
            scale(2, 2);
            break;
        case 4:
            cout << "Showing Rotation (45 degrees)...\n";
            rotateTriangle(45);
            break;
        case 5:
            cout << "Showing Reflection about X-axis...\n";
            reflectX();
            break;
        case 6:
            cout << "Showing Reflection about Y-axis...\n";
            reflectY();
            break;
        case 7:
            cout << "Showing Shearing in X...\n";
            shearX(0.5);
            break;
        case 8:
            cout << "Showing Shearing in Y...\n";
            shearY(0.5);
            break;
        case 9:
            cout << "All operations done. Exiting...\n";
            exit(0);
        }

        glutPostRedisplay(); // Refresh screen after each step
    }
}

// ======== MAIN ======== //
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Transformations - Step by Step");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}