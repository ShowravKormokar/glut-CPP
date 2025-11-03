#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "include/jet.h"
#include "include/moveBlocks.h"
using namespace std;

// -------- Global Variables
float jetX = -0.7f, jetY = 0.0f; // Place of Jet
float jetSpeed = 0.05f;          // Move per key press
int gameOver = 0;                // Game over or not

const int maxBlocks = 5;
float blockX[maxBlocks], blockY[maxBlocks], blockW[maxBlocks], blockH[maxBlocks];
float blockSpeed = 0.02f; // Block speed

// --------- Initialization (Random Block)
void initBlocks()
{
    srand(time(0)); // For random create
    for (int i = 0; i < maxBlocks; i++)
    {
        blockX[i] = (float)(rand() % 100) / 100.0f + 1.0f; // Block start out of window
        blockY[i] = (float)(rand() % 100) / 50.0f - 1.0f;  // -1 to +1
        blockW[i] = 0.1f + (float)(rand() % 10) / 50.0f;   // random width
        blockH[i] = 0.1f + (float)(rand() % 10) / 50.0f;   // random height
    }
}

// ------------ Display Function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (gameOver)
    {
        glColor3f(1, 0, 0);
        glRasterPos2f(-0.2f, 0.0f);
        const char *msg = "GAME OVER!";
        for (int i = 0; msg[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[i]);
    }
    else
    {
        drawJet(jetX, jetY);
        drawBlocks(blockX, blockY, blockW, blockH, maxBlocks, blockSpeed, jetX, jetY, gameOver);
    }

    glutSwapBuffers();
}

//------------ Keyboard Controls
void specialKeys(int key, int x, int y)
{
    if (gameOver)
        return; // Game End

    switch (key)
    {
    case GLUT_KEY_UP:
        if (jetY + 0.08f < 1.0f) // Top limit
            jetY += jetSpeed;
        break;

    case GLUT_KEY_DOWN:
        if (jetY > -1.0f) // Lower limit
            jetY -= jetSpeed;
        break;

    case GLUT_KEY_LEFT:
        if (jetX > -1.0f) // Left limit
            jetX -= jetSpeed;
        break;

    case GLUT_KEY_RIGHT:
        if (jetX + 0.2f < 1.0f) // Right limit (Including jet width)
            jetX += jetSpeed;
        break;
    }

    glutPostRedisplay(); // Refresh window
}

// ------------- Timer Function (Game Loop)
void update(int value)
{
    if (!gameOver)
    {
        glutPostRedisplay();
        glutTimerFunc(16, update, 0); // ~60fps
    }
}

// ------------ Main Function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Jet Game - GLUT");
    glClearColor(0.0, 0.0, 0.2, 1.0); // Mid night blue

    initBlocks();

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
