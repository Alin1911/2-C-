#include<stdio.h>
int fibonacci(int k);
int main(){
	int n;
	int i;
	printf("n=");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		fibonacci(i);
	printf("%d ",fibonacci(i-1));
}
int fibonacci(int k){
	if ((k==1)||(k==2))
		return 1;
	else
		return (fibonacci(k-1)+fibonacci(k-2));
}
