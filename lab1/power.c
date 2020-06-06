#include<stdio.h>
double power(int base, int pow1);
int main(){
	int base, pow1;
	scanf("%d",&base);
	scanf("%d",&pow1);
	printf("%f\n",power(base,pow1));
}
double power(int base, int pow){
	if(pow == 0){
		return 1;
	}
	else
	{	if(pow % 2 == 0 )
			{return power(base,pow/2)*power(base,pow/2);}
		else
			{return base*power(base,pow/2)*power(base,pow/2);}
	}
	
}
