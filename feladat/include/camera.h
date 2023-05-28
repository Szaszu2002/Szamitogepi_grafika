#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"
#include "texture.h"

#include <stdbool.h>



typedef struct Camera
{
    vec3 position;
    vec3 rotation;
    vec3 speed;
    Shark* center;
    bool is_preview_visible;
} Camera;

void init_camera(Camera* camera, Shark* shark);
void update_camera(Camera* camera, double time);
void set_view(const Camera* camera);
void rotate_camera(Camera* camera, double horizontal, double vertical);
void set_camera_speed(Camera* camera, double speed);
void set_camera_side_speed(Camera* camera, double speed);
void rotate_around_shark(Camera* camera, double angle);
void set_camera_vertical_speed(Camera* camera, double speed);

#endif