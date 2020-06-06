#include <stdio.h>
int count_equals(int value, int *vector, size_t vector_length);
int main(){
	int v[99], value;
	size_t vector_length;
	scanf( "%ld", &vector_length );
	scanf( "%d", &value );
	for(int i = 0; i < vector_length; i++){
		scanf("%d",&v[i]);
	}
	printf("%d",count_equals(value,v,vector_length));
	return 0;
}
 int count_equals(int value, int *vector, size_t vector_length){
	if( vector_length == 0 ){
		return 0;
	}
	else{
		if( vector[ vector_length - 1 ] == value ){
			return 1 + count_equals(value, vector, vector_length - 1 );
			}
		else
			{
			return 0 + count_equals(value, vector, vector_length - 1 );
			}
		}
	}



