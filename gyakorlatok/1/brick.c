#include "brick.h"
#include <math.h>
void set_size(Brick* brick)
{
    double a,b,c;
    int ok=0;
    do{
        printf("Adja meg a teglatest oldalait szokozzel elvalasztva!")
        if(scanf("%lf %lf %lf",&a,&b,&c)!=3||a<0||b<c||c<0)
        {
            ok=0;
        }
        else
        {
            ok=1;
        }
    }while(!ok);
    brick->a = a;
    brick->b = b;
    brick->c = c;
    return;
}
double calc_volume(const Brick brick)
{
    double v = brick->a * brick->b * brick->c;
    return v;
}
double calc_surface(const Brick brick)
{
    double a = 2(brick->a * brick->b + brick->b * brick->c + brick->c * brick->a);
    return a;
}