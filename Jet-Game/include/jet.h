#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

void drawJet(float jetX, float jetY)
{
    // --- Jet Body ---
    glColor3f(0.1, 0.8, 1.0);
    glRectf(jetX, jetY, jetX + 0.15f, jetY + 0.08f);

    // --- Jet Nose ---
    glColor3f(1, 0.3, 0.3);
    glBegin(GL_TRIANGLES);
    glVertex2f(jetX + 0.15f, jetY + 0.04f);
    glVertex2f(jetX + 0.2f, jetY + 0.08f);
    glVertex2f(jetX + 0.2f, jetY);
    glEnd();

    // --- Left Wing ---
    glColor3f(1, 0.3, 0.3);
    glBegin(GL_TRIANGLES);
    glVertex2f(jetX + 0.05f, jetY + 0.04f); // Middle point (attach to body)
    glVertex2f(jetX - 0.05f, jetY + 0.08f); // Top-left wing tip
    glVertex2f(jetX, jetY + 0.04f);         // Connection to body
    glEnd();

    // --- Right Wing ---
    glColor3f(1, 0.3, 0.3);
    glBegin(GL_TRIANGLES);
    glVertex2f(jetX + 0.10f, jetY + 0.04f); // Middle point (attach to body)
    glVertex2f(jetX + 0.18f, jetY - 0.04f); // Bottom-right wing tip
    glVertex2f(jetX + 0.15f, jetY + 0.04f); // Connection to body
    glEnd();
}
