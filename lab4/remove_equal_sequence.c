#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	double data;
	struct node *prev;
	struct node *next;
}node_t;

void push(node_t **head, node_t *new_node){
	double valoare;
	scanf("%lf", &valoare);
	new_node = (node_t *) malloc (sizeof(node_t));
	node_t *last = (*head);
	new_node->data = valoare;
	new_node->next = NULL;
	if ((*head) == NULL){
		new_node->prev = NULL;
		(*head) = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}


void print(node_t *head){
	while (head != NULL)
	{
		printf("%0.f ", head->data);
		head = head->next;
	}
	printf("\n");
}

void remove_equal_sequence( node_t ** list_o){
	node_t *aux ,*current , *list;
	list = *list_o;
	aux = current = *list_o;
	int final = 1, testez ,contor = 0;
	for( list; list!=NULL; list = list->next ){
		if(list->data == testez && contor == 0){
			current = list->prev->prev;
			contor++;
		}
		if(list->data == testez) {
			final++;
		} 
		else
		{
			aux = list;
			contor = 0;
			if(final >= 3) {
				current->next =aux;
				aux->prev = current;
			}
			final = 1; 
		}
		if(!list->next) {
			if(final >= 3) {
				current->next = NULL;
			}
		}		
	testez = list->data;
	}

}


int main()
{
	node_t *list_o = NULL;
	node_t *nou;
	for (int i = 0 ; i < 13; i++) {
		push(&list_o, nou);
	}
	remove_equal_sequence(&list_o);
	
	print(list_o);
	free(list_o);
}