#include<stdio.h>
double nth_random_value(size_t n);

int main(){
	int n;
	scanf("%d",&n);
	printf("%f\n",nth_random_value(n));
}
 double nth_random_value(size_t n){
 	if(n==1){
 		return 0.45;
 	}else
 	{
 		return (3.75*nth_random_value( n-1)*(1- nth_random_value( n-1)));
 	}
}
