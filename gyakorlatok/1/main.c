#include "brick.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
    Brick brick;
    double v;
    double a;
    set_size(&brick);
    v=calc_volume(&brick);
    a=calc_surface(&brick);
    printf("Brick volume: %.2lf\nBrick surface: %.2lf",v,a);
    return 0;
}