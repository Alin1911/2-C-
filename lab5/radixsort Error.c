#include<stdio.h>
#include<stdlib.h>
//am incercat dar nu merge :))
typedef int ElType;
typedef struct cell {
	ElType elem;
	struct cell *next;
} Stack;

Stack* front(ElType e, Stack *s) {
	Stack *nou; 
	nou = (Stack*) malloc(sizeof(Stack));
	if (nou == NULL) {
		return NULL;  
	} 
	nou->elem = e; 
	if (s == NULL) {
		nou->next = NULL; 
		s = nou; 
	}
	else{
		nou->next = s; 
		s = nou; 
	}
	return s;
}

Stack* initstack(Stack *s) {
 	s = NULL;
 	return s;
}

Stack* getMax(Stack **arr, int n) 
{ 
	Stack *mx = *arr;
	Stack *aux = *arr;
	for (aux ;aux->next;aux=aux->next) 
		if (aux->next > mx) 
			mx = aux->next; 
	return mx; 
} 

void countSort(Stack **arr, int n, int exp) 
{ 
	Stack *aux;
	int output[n];
	int i, count[10] = {0};
	aux = *arr;
	while(aux->next){
		count[ ((aux->elem)/exp)%10 ]++; 
		aux=aux->next;
	}

	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	for (i = n - 1; i >= 0; i--) 
	aux = *arr;
	i=n-1;
	while(aux->next){ 
		output[count[ ((aux->elem)/exp)%10 ] - 1] = aux->elem; 
		count[ ((aux->elem)/exp)%10 ]--; 
		i--;
		aux=aux->next;
	}  
	i=0;
	aux = *arr;
	while(aux->next){ 
		aux->elem=output[i];
		i++;
		aux=aux->next;
	} 
} 

void radixsort(Stack **arr, int n) 
{ 

	Stack * m = getMax(arr, n); 
	for (int exp = 1; (m->elem)/exp > 0; exp *= 10){
		countSort(arr, n, exp); }
} 

void printstack(Stack *s) {
	Stack *aux; 
	aux = s;
	if (aux == NULL){
		printf("\n Stiva vida \n");
	}
	else { printf("Continutul stivei este: \n");
		while (aux != NULL) {
			printf(" %d", aux->elem); 
			aux = aux->next; 
		}
		printf("\n");
	}
}
int main() 
{ 
	Stack *s = NULL; 
	s = initstack(s);
	int arr[] = {3,2,10,24,45,12,3,2}; 
	for(int i=0;i<8;i++){
		int n = sizeof(arr)/sizeof(arr[0]);
		s = front(arr[i], s);
	}
	printstack(s);
	int n = sizeof(arr)/sizeof(arr[0]); 
	radixsort(&s, n); 
	printstack(s); 
	return 0; 
} 
