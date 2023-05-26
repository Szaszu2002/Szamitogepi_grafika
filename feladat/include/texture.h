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
typedef struct Other
{
    vec3 position;
    vec3 rotation;
    int texture_id;
    Model other;

}Other;
void init_shark(Shark* shark);
void init_fish1(Fish* fish);
void init_fish2(Fish* fish);
void init_fish3(Fish* fish);
void init_fish4(Fish* fish);
void init_fish5( Fish* fish);
void init_other1(Other* other);
void init_other2(Other* other);
void init_other3(Other* other);
void init_other4(Other* other);
typedef GLubyte Pixel[3];
GLuint load_texture(char* filename);
GLuint load_texture_shark(char* filename);
void render_shark(const Shark* shark);
void render_fish(const Fish* fish);
void render_other(const Other* other);

#endif