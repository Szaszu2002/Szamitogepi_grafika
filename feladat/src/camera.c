#include "camera.h"

#include <GL/gl.h>

#include <math.h>

void init_camera(Camera* camera, Shark* shark)
{
    camera->position.x = 0.0;
    camera->position.y = 0.0;
    camera->position.z = 1.0;
    camera->rotation.x = 0.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = 0.0;
    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;

    camera->center=shark;

    camera->is_preview_visible = false;
}

void update_camera(Camera* camera, double time)
{
    double angle;
    double side_angle;
    vec3 new_position;

    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);
    
    new_position.x = camera->position.x + cos(angle) * camera->speed.y * time;
    new_position.x += cos(side_angle) * camera->speed.x * time;
    new_position.y = camera->position.y + sin(angle) * camera->speed.y * time;
    new_position.y += sin(side_angle) * camera->speed.x * time;
    new_position.z = camera->position.z + camera->speed.z * time;


    update_shark_position(camera->center, &new_position);

    camera->position.x += cos(angle) * camera->speed.y * time;
    camera->position.y += sin(angle) * camera->speed.y * time;
    camera->position.x += cos(side_angle) * camera->speed.x * time;
    camera->position.y += sin(side_angle) * camera->speed.x * time;
    camera->position.z += camera->speed.z * time;
}

void rotate_around_shark(Camera* camera, double angle)
{
    float x, y;

    angle = degree_to_radian(angle);
    camera->position.x -= camera->center->real_position.x;
    camera->position.y -= camera->center->real_position.z;

    x = camera->position.x;
    y = camera->position.y;

    camera->position.x = cos(angle) * x - sin(angle) * y + camera->center->real_position.x;
    camera->position.y = sin(angle) * x + cos(angle) * y + camera->center->real_position.z;
}

void set_view(const Camera* camera)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}

void rotate_camera(Camera* camera, double horizontal, double vertical)
{
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}

void set_camera_speed(Camera* camera, double speed)
{
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed)
{
    camera->speed.x = speed;
}

void show_texture_preview()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1, 1, -3);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, -3);
    glTexCoord2f(1, 1);
    glVertex3f(1, -1, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, -3);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}
void set_camera_vertical_speed(Camera* camera, double speed)
{
    camera->speed.z = speed;
}