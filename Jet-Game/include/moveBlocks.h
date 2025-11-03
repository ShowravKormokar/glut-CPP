#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "checkCollision.h"
using namespace std;

void drawBlocks(float blockX[], float blockY[], float blockW[], float blockH[],
                int maxBlocks, float blockSpeed, float jetX, float jetY, int &gameOver)
{
    glColor3f(0.8, 0.4, 0.1);
    for (int i = 0; i < maxBlocks; i++)
    {
        glRectf(blockX[i], blockY[i], blockX[i] + blockW[i], blockY[i] + blockH[i]);
        blockX[i] -= blockSpeed;

        // If out of window
        if (blockX[i] < -1.2f)
        {
            blockX[i] = 1.0f + (float)(rand() % 50) / 50.0f;
            blockY[i] = (float)(rand() % 100) / 50.0f - 1.0f;
            blockW[i] = 0.1f + (float)(rand() % 10) / 50.0f;
            blockH[i] = 0.1f + (float)(rand() % 10) / 50.0f;
        }

        // Collision check
        if (checkCollision(jetX, jetY, 0.15f, 0.08f, blockX[i], blockY[i], blockW[i], blockH[i]))
        {
            gameOver = 1; // Update main variable since it's now a reference
        }
    }
}