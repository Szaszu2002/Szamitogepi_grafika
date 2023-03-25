#include "pad.h"

#include <GL/gl.h>

void init_pad(Pad* pad, float x, float table_height, enum ColorTheme color_theme)
{
    pad->x = x;
    pad->y = 0;
    pad->width = 50;
    pad->height = 120;
    pad->limit = table_height - pad->height;
    pad->speed = 0;
    pad->color_theme = color_theme;
}

void set_pad_position(Pad* pad, float position)
{
    if (position < 0.0) {
        pad->y = 0.0;
    } else if (position > pad->limit) {
        pad->y = pad->limit;
    } else {
        pad->y = position;
    }
}

void set_pad_speed(Pad* pad, float speed)
{
    pad->speed = speed;
}

void update_pad(Pad* pad, double time)
{
    float new_position;

    new_position = pad->y + pad->speed * time;
    set_pad_position(pad, new_position);
}

void render_pad(Pad* pad)
{
    float x1, x2, y1, y2;

    x1 = pad->x;
    x2 = x1 + pad->width;
    y1 = pad->y;
    y2 = y1 + pad->height;

    glBegin(GL_QUADS);
    if (pad->color_theme == RED_THEME) { //ball oldali ütő színének állítása
        glColor3f(0.8, 0.0, 0.0);
        glVertex2f(x1, y1);
        glColor3f(0.7, 0.1, 0.0);
        glVertex2f(x2, y1);
        glColor3f(0.5, 0.9, 0.0);
        glVertex2f(x2, y2);
        glColor3f(0.7, 0.1, 0.0);
        glVertex2f(x1, y2);
    } else if (pad->color_theme == GREEN_THEME) { //jobb oldali ütő színének állítása
        glColor3f(0.0, 0.3, 0.0);
        glVertex2f(x1, y1);
        glColor3f(0.0, 0.7, 0.2);
        glVertex2f(x2, y1);
        glColor3f(0.0, 1.0, 0.7);
        glVertex2f(x2, y2);
        glColor3f(0.0, 0.8, 0.1);
        glVertex2f(x1, y2);
    }
    glEnd();
}
