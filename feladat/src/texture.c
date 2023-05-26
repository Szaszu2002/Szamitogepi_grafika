#include "texture.h"
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

GLuint load_texture(char* filename)
{
    SDL_Surface* surface;
    GLuint texture_name;

    surface = IMG_Load(filename);

    glGenTextures(1, &texture_name);

    glBindTexture(GL_TEXTURE_2D, texture_name);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, (Pixel*)(surface->pixels));

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return texture_name;
}

void render_shark(const Shark* shark)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBindTexture(GL_TEXTURE_2D, shark->texture_id);

    glTranslatef(shark->position.x,shark->position.y,shark->position.z);
    glScalef(0.05,0.05,0.05);

    draw_model(&(shark->shark));
    //glPopMatrix();
    //printf("Hello");
    
}
void init_shark(Shark* shark)
{
    shark->position.x=0;
    shark->position.z=-1;
    shark->position.y=0;

    shark->rotation.x=0;
    shark->rotation.y=0;
    shark->rotation.z=0;

    load_model(&(shark->shark), "assets/models/whale.obj");
    shark->texture_id = load_texture("assets/textures/whale.jpg");
}
void init_fish1(Fish* fish)
{
    fish->position.x=3;
    fish->position.z=2;
    fish->position.y=1;
    fish->state=true;
    fish->rotation.x=0;
    fish->rotation.y=0;
    fish->rotation.z=0;

    load_model(&(fish->fish), "assets/models/blue_fish.obj");
    fish->texture_id = load_texture("assets/textures/blue_fish_texture.jpg");
}
void init_fish2(Fish* fish)
{
    fish->position.x=1;
    fish->position.z=2;
    fish->position.y=-4;
    fish->state=true;
    fish->rotation.x=0;
    fish->rotation.y=0;
    fish->rotation.z=0;

    //load_model(&(fish->fish), "assets/models/purple_fish.obj");
    //fish->texture_id = load_texture("assets/textures/purple_fish_texture.jpg");
    load_model(&(fish->fish), "assets/models/yellow_fish.obj");
    fish->texture_id = load_texture("assets/textures/yellow_fish_texture.jpg");
}
void init_fish3(Fish* fish)
{
    fish->position.x=4;
    fish->position.z=1;
    fish->position.y=5;
    fish->state=true;
    fish->rotation.x=0;
    fish->rotation.y=0;
    fish->rotation.z=0;

    load_model(&(fish->fish), "assets/models/yellow_fish.obj");
    fish->texture_id = load_texture("assets/textures/yellow_fish_texture.jpg");
}
void init_fish4(Fish* fish)
{
    fish->position.x=1;
    fish->position.z=4;
    fish->position.y=1;
    fish->state=true;
    fish->rotation.x=0;
    fish->rotation.y=0;
    fish->rotation.z=0;

    load_model(&(fish->fish), "assets/models/blue_fish.obj");
    fish->texture_id = load_texture("assets/textures/blue_fish_texture.jpg");
}
void init_fish5(Fish* fish)
{
    fish->position.x=2;
    fish->position.z=5;
    fish->position.y=2;
    fish->state=true;
    fish->rotation.x=0;
    fish->rotation.y=0;
    fish->rotation.z=0;

    //load_model(&(fish->fish), "assets/models/purple_fish.obj");
    //fish->texture_id = load_texture("assets/textures/purple_fish_texture.jpg");
    load_model(&(fish->fish), "assets/models/yellow_fish.obj");
    fish->texture_id = load_texture("assets/textures/yellow_fish_texture.jpg");
}

void render_fish(const Fish* fish)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, fish->texture_id);

    glTranslatef(fish->position.x,fish->position.y,fish->position.z);
    glScalef(0.2,0.2,0.2);

    draw_model(&(fish->fish));
    glPopMatrix();
}
void init_other1(Other* other)
{
    other->position.x=-6;
    other->position.z=7;
    other->position.y=-7;

    other->rotation.x=0;
    other->rotation.y=0;
    other->rotation.z=0;

    load_model(&(other->other), "assets/models/turtle2.obj");
    other->texture_id = load_texture("assets/textures/turtle_texture.jpg");
}
void init_other2(Other* other)
{
    other->position.x=4;
    other->position.z=-5;
    other->position.y=-3;

    other->rotation.x=0;
    other->rotation.y=0;
    other->rotation.z=0;

    load_model(&(other->other), "assets/models/red_coral.obj");
    other->texture_id = load_texture("assets/textures/red_coral_texture.jpg");
}
void init_other3(Other* other)
{
    other->position.x=-2;
    other->position.z=-3;
    other->position.y=6;

    other->rotation.x=0;
    other->rotation.y=0;
    other->rotation.z=0;

    load_model(&(other->other), "assets/models/seahorse.obj");
    other->texture_id = load_texture("assets/textures/seahorse_texture.jpg");
}
void init_other4(Other* other)
{
    other->position.x=-4;
    other->position.z=-5;
    other->position.y=-7;

    other->rotation.x=0;
    other->rotation.y=0;
    other->rotation.z=0;

    load_model(&(other->other), "assets/models/shell.obj");
    other->texture_id = load_texture("assets/textures/shell.jpg");
}
void render_other(const Other* other)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, other->texture_id);

    glTranslatef(other->position.x,other->position.y,other->position.z);
    glScalef(0.1,0.1,0.1);

    draw_model(&(other->other));
    glPopMatrix();
}