#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

//--------- Collision Detection Function
bool checkCollision(float x1, float y1, float w1, float h1,
                    float x2, float y2, float w2, float h2)
{
    // No collision cases:
    if (x1 + w1 < x2)
        return false; // Jet right < Block left
    if (x1 > x2 + w2)
        return false; // Jet left > Block right
    if (y1 + h1 < y2)
        return false; // Jet top < Block bottom
    if (y1 > y2 + h2)
        return false; // Jet bottom > Block top

    return true; // Otherwise collision
}