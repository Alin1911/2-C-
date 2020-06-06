#include <math.h>
#include <stdio.h>

double my_sqrt(double num, double prev)
{
    float urm = (prev+num/prev)/2;
    if (fabs(urm-prev)<0.001*urm)
        return urm;
    return my_sqrt(num, urm);
}

int main() {
    int x,a=1;
    scanf("%d", &x);
    printf("%0.f\n", my_sqrt(x, a));
    return 0;
}