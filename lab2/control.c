#include<stdio.h>
int control(int x);

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",control(n));
}
int control(int x){
	int s=0;
	while(x){
	if( (x%10)%2 != 0 )
		s = s + x%10 ;
	x=x/10;
	}
	if ( s/10 != 0 )
	 	return control(s);
	else 
		return s;

}