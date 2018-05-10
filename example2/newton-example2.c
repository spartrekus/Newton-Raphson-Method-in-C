
/*
Enter x0, allowed error and maximum iterations
2 0.0001 10
*/


#include<stdio.h>
#include<math.h>
float f(float x)
{
    //return x*log10(x) - 1.2;
    return x*x*x - 2 * x -1;
}

float df (float x)
{
    //return log10(x) + 0.43429;
    return 3*x*x-2;
}

void main()
{
    int itr, maxmitr;
    float h, x0, x1, allerr;
    //printf("\nEnter x0, allowed error and maximum iterations\n");
    //scanf("%f %f %d", &x0, &allerr, &maxmitr);
    x0 = 5; 
    allerr = 0.000001; 
    maxmitr = 20 ; 
    for (itr=1; itr<=maxmitr; itr++)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
        printf(" At Iteration no. %3d, x = %9.6f\n", itr, x1);
        if (fabs(h) < allerr)
        {
            printf("After %3d iterations, root = %8.6f\n", itr, x1);
            return 0;
        }
        x0=x1;
    }
    printf(" The required solution does not converge or iterations are insufficient\n");
    return 1;
}
