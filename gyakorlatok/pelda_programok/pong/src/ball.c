#include "ball.h"

#include <GL/gl.h>

#include <math.h>

void init_ball(Ball* ball, float x, float y)
{
    ball->x = x;
    ball->y = y;
    ball->radius = 30;  //labda méretének állítása
    ball->speed_x = 150;  //labda gyorsaságának állítása
    ball->speed_y = 150;
}

void update_ball(Ball* ball, double time)  //labda gyorsaságának állítása
{
    ball->x += ball->speed_x * 2*time;
    ball->y += ball->speed_y * 2*time;
}

void render_ball(Ball* ball)
{
    double angle;
    double x;
    double y;

    glPushMatrix();
    glTranslatef(ball->x, ball->y, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8, 0.5, 0.8);   //labda színének állítása
    glVertex2f(0, 0);
    angle = 0;
    while (angle < 2.0 * M_PI + 1) {
        x = cos(angle) * ball->radius;
        y = sin(angle) * ball->radius;
        glVertex2f(x, y);
        angle += 0.2;  //labda körré alakítás, minnél kisebb a szám annál gömbölyűbb
    }
    glEnd();
    glPopMatrix();
}
