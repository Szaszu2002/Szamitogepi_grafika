#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Shark shark;
    Material material;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);
void rend_shark(Scene* scene);
void rend_fish1(Scene* scene);
void rend_fish2(Scene* scene);
void rend_fish3(Scene* scene);
void rend_fish4(Scene* scene);
void rend_fish5(Scene* scene);
/**
 * Set the lighting of the scene.
 */
void set_lighting();

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
