#ifndef APP_H
#define APP_H

#include "camera.h"
#include "scene.h"

#include <SDL2/SDL.h>

#include <stdbool.h>

#define VIEWPORT_RATIO (4.0 / 3.0)
#define VIEWPORT_ASPECT 50.0
typedef struct Help
{
    GLuint texture_id;
}Help;
typedef struct App
{
    SDL_Window* window;
    SDL_GLContext gl_context;
    bool is_running;
    double uptime;
    Camera camera;
    Help help;
    Scene scene;
    GLuint finish_texture;
} App;

void init_app(App* app, int width, int height);
void init_opengl();
void reshape(GLsizei width, GLsizei height);
void handle_app_events(App* app);
void update_app(App* app);
void render_app(App* app);
void destroy_app(App* app);
void init_help(Help* help);
void render_help(Help* help);

#endif