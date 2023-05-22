#ifndef TEXTURE_H
#define TEXTURE_H

#include "utils.h"
#include <obj/model.h>
#include <GL/gl.h>
#include <stdbool.h>

typedef struct Shark
{
    vec3 position;
    vec3 rotation;
    int texture_id;
    Model shark;
} Shark;
typedef struct Fish
{
    vec3 position;
    vec3 rotation;
    int texture_id;
    bool state;
    Model fish;
} Fish;
void init_shark(Shark* shark);
void init_fish1(Fish* fish);
void init_fish2(Fish* fish);
void init_fish3(Fish* fish);
void init_fish4(Fish* fish);
void init_fish5( Fish* fish);
typedef GLubyte Pixel[3];
GLuint load_texture(char* filename);
GLuint load_texture_shark(char* filename);
void render_shark(const Shark* shark);
void render_fish(const Fish* fish);

#endif