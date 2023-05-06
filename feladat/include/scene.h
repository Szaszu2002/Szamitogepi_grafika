#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model fish;
    Material material;
    GLuint texture_id;
} Scene;

void init_scene(Scene* scene);

void set_lighting();

#endif