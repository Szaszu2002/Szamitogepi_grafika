#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init_dentity_matrix(float v[3][3]);
void scalar_multiplication(float v[3][3],float scalar);
void multiply_matrices(float v[3][3], float m[3][3], float n[3][3]);
void transform_point(float point[3], float t[3][3], float outcome[]);
void scale();
void shift();
void rotate();

int main()
{
    float v[3][3];
    init_dentity_matrix(v);
    float scalar;
    int ok;
    do{
        printf("Kerem adja meg a skalar szamot!");
        if(scanf("%lf",&scalar)!=1)
        {
            printf("Hibas adat");
            ok=0;
        }
        else
        {
            ok=1;
        }
    }while(!ok);
    scalar_multiplication(v,scalar);
    float m[3][3]={ { 13, -15,  18},
                    {  5, -10,   8},
                    { -2,   1,  -4}}
    float n[3][3];
    multiply_matrices(v,m,n);
    float point[3]={13, 15, 18};
    float outcome[3];
    float t[3][3];
    transform_point(point,t,outcome);

    return 0;
}

void init_dentity_matrix(float v[3][3])
{
    int i,j;
    for (int i = 0; i < 3; i++) 
    {
		for (int j = 0; j < 3+3; j++) 
        {
			if (j == i + 3) 
            {
				a[i][j] = 1;
			} 
            else 
            {
			    a[i][j] = 0;
			}
		}
	}
    return;
}

void scalar_multiplication(float v[3][3],float scalar)
{
    int i,j;
    for (i = 0; i < 3; ++i) 
    {
        for (j = 0; j < 3; ++j) 
        {
            matrix[i][j] = matrix[i][j]*scalar;
        }
    }
    return;
}

void multiply_matrices(float v[3][3], float m[3][3], float n[3][3])
{
    int i, j, k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                n(i)(j)=n(i)(j)+v(i)(k)*m(k)(j);
            }
        }
    }
    return;
}
void transform_point(float point[3], float t[3][3],float outcome[3])
{
    float auxiliary[3];
    for(i=0;i<3;i++)
    {
        auxiliary[i]=0;
        for(j=0;j<3;j++)
        {
            auxiliary[i]+=(point[j]*t[j][i]);
            outcome[i]=auxiliary[i]%2;
        }
    }
    return;

}