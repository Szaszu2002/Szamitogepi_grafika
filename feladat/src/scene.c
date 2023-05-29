#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    init_shark(&(scene->shark));
    init_fish1(&(scene->fish[0]));
    init_fish2(&(scene->fish[1]));
    init_fish3(&(scene->fish[2]));
    init_fish4(&(scene->fish[3]));
    init_fish5(&(scene->fish[4]));
    init_other1(&(scene->other[0]));
    init_other2(&(scene->other[1]));
    init_other3(&(scene->other[2]));
    init_other4(&(scene->other[3]));
    

    scene->material.ambient.red = 0.5;
    scene->material.ambient.green = 0.5;
    scene->material.ambient.blue = 0.5;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 0.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;
    scene->power=0;
    scene->counter=5;
}
// valós helyzet függvény!!!!

void set_lighting(Scene* scene)
{
    float power=scene->power;
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    float ambient_light[] = { power, power, power, 1};
    float diffuse_light[] = { power, power, power, 1};
    float specular_light[] = { power, power, power, 1};
        
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    
}
void light_on(Scene* scene)
{
    if(scene->power<1)
    {
        scene->power=scene->power+0.05;
        
    }
}
void light_off(Scene* scene)
{
    if(scene->power>0.1)
    {
        scene->power=scene->power-0.05;
        
    }
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene)
{
    touch_fish(scene);
}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    for(int i=0;i<FISH_COUNT;i++)
    {
        if(scene->fish[i].state)
        {
            render_fish(&(scene->fish[i]));
        }
    }
    for(int i=0;i<OTHER_COUNT;i++)
    {
        render_other(&(scene->other[i]));
    }
    set_lighting(scene);
    draw_origin();
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void rend_shark(Scene* scene)
{
    render_shark(&(scene->shark));
}
void touch_fish(Scene* scene)
{
    for(int i=0;i<5;i++)
    {
        if(scene->fish[i].state && touch(&(scene->shark),&(scene->fish[i])))
        {
            scene->fish[i].state=false;
            scene->shark.point++;
            scene->counter--;
            printf("\n %d",scene->counter);
        }
    }
}
