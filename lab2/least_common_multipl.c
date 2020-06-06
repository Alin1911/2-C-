#include<stdio.h>
int least_common_multiple(unsigned a, unsigned b); 
unsigned greatest_common_divisor(unsigned a, unsigned b) {
	while (a != b)
	{
		if (a > b) 
			a -=b;
		else 
			if (b > a) 
				b -= a;
	}
	return a;
}
int main(){
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d",least_common_multiple(a, b));
}
int least_common_multiple(unsigned a, unsigned b){
	return (a*b)/greatest_common_divisor(a,b);

}