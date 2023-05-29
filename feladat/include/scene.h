#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

#define FISH_COUNT 5
#define OTHER_COUNT 4

typedef struct Scene
{
    Shark shark;
    Fish fish[FISH_COUNT];
    Other other[OTHER_COUNT];
    Material material;
    float power;
    int counter;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);
void rend_shark(Scene* scene);
void touch_fish(Scene* scene);
void light_on(Scene* scene);
void light_off(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(Scene* scene);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
