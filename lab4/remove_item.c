#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *prev;
	struct node *next;
}*List;

void remove_items(List *head) {
	List curent= *head;
	int i=1;
	if (!(*head))
		return;
	for (curent;curent->next !=NULL; curent=curent->next){
		if(curent->value % 2 == 0 && i%2==1){
			i++;
			if(curent->next != NULL){
				curent->next->prev=curent->prev;
				curent->prev->next=curent->next;
			}
			else
			{
				curent->prev->next=NULL;
			}
			free(curent);
		}
		else
			i++;
	}
}
int main(){
	return 0;
}