#ifndef BRICK_H
#define BRICK_H

typedef struct BRICK
{
	double a;
	double b;
	double c;
} Brick;

void set_size(Brick* brick);
double calc_volume(const Brick brick);
double calc_surface(const Brick brick);
#endif