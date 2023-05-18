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
void init_shark(Shark* shark);
void init_fish1(Shark* shark);
void init_fish2(Shark* shark);
void init_fish3(Shark* shark);
void init_fish4(Shark* shark);
void init_fish5(Shark* shark);
typedef GLubyte Pixel[3];
GLuint load_texture(char* filename);
GLuint load_texture_shark(char* filename);
void render_shark(const Shark* shark);
void render_fish1(const Shark* shark);
void render_fish2(const Shark* shark);
void render_fish3(const Shark* shark);
void render_fish4(const Shark* shark);
void render_fish5(const Shark* shark);
#endif