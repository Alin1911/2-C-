#include<stdio.h>	
void euclid(int a, int b, int *d)	
{
    if (b == 0) {
        *d = a;
    } else
        euclid(b, a % b, d);
}
int main(){
	int a,b,*d;
	scanf("%d",&a);
	scanf("%d",&b);
	euclid(a,b,&d);
	printf("%d",*(&d));
}