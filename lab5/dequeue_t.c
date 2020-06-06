#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_SUCCESS 0
#define ERROR_DEQUEUE_EMPTY -1
#define ERROR_DEQUEUE_INTERNAL -2

typedef struct node{
	double value;
	struct node *next;
	struct node *prev;
} node_t;

typedef struct {
	node_t * front ;
	node_t * back ;
	size_t size ;
} dequeue_t ;

dequeue_t * alloc_deq ( void )
{
	dequeue_t * dq = malloc(sizeof(dequeue_t));
	dq->front = NULL;
	dq->back = NULL;
	dq->size = 0;
	return dq;
}

int front ( dequeue_t * deq , double * value )
{
	node_t *cap = deq->front;
	if (cap != NULL) {
		*value = cap->value;
		return ERROR_SUCCESS;
	}

	return ERROR_DEQUEUE_EMPTY;
}

int back ( dequeue_t * deq , double * value )
{
	node_t *tail = deq->back;
	if (tail != NULL) {
		*value = tail->value;
		return ERROR_SUCCESS;
	}

	return ERROR_DEQUEUE_EMPTY;
}

int push_front ( dequeue_t * deq , double value )
{
	node_t *cap = deq->front;
    node_t *new_node = malloc(sizeof(node_t));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = value;
	if (new_node == NULL) 
		return ERROR_DEQUEUE_INTERNAL;
	if (cap == NULL) {
		deq->back = deq->front = new_node;
		deq->size ++;
		return ERROR_SUCCESS;
	} else {
		new_node->next = cap;
		cap->prev = new_node;
		deq->front = new_node;
		deq->size ++;
		return ERROR_SUCCESS;
	}
	return ERROR_DEQUEUE_INTERNAL;
}

int push_back ( dequeue_t * deq , double value )
{
	node_t *tail = deq->back;
	node_t *new_node = malloc(sizeof(node_t));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = value;
	if (new_node == NULL) 
		return ERROR_DEQUEUE_INTERNAL;

	if (tail == NULL) {
		deq->back = deq->front = new_node;
		deq->size ++;
		return ERROR_SUCCESS;
	} else {
		new_node->prev = tail;
		tail->next = new_node;
		deq->back = new_node;
		deq->size ++;
		return ERROR_SUCCESS;
	}
	return ERROR_DEQUEUE_INTERNAL;
}

void pop_front ( dequeue_t * deq )
{
	if (deq->front == NULL)
		return;
	if (deq->front == deq->back) {
		free(deq->front);
		deq->front = deq->back = NULL;
		deq->size = 0;
	} else {
		node_t *cap = deq->front;
		deq->front = deq->front->next;
		deq->front->prev = NULL;
		deq->size --;
		free(cap);
	}
}

void pop_back ( dequeue_t * deq )
{
	if (deq->back == NULL)
		return;
	if (deq->front == deq->back) {
		free(deq->front);
		deq->front = deq->back = NULL;
		deq->size = 0;
	} else {
		node_t *tail = deq->back;
		deq->back = deq->back->prev;
		deq->back->next = NULL;
		deq->size --;
		free(tail);
	}
}

size_t size ( dequeue_t * deq )
{
	return deq->size;
}

void print(dequeue_t * dq)
{
	node_t * cap = dq->front;
	while (cap) {
		printf("%0.lf ", cap->value);
		cap = cap->next;
	}
	printf("\n");
}

void main()
{
	dequeue_t * sp = alloc_deq();
	double value;

	printf("Verificam stiva la inceput\n");
	printf("%d %d\n", front(sp, &value), back(sp, &value) );
	value = 3;
	printf("Verificam push_front %d\n", push_front(sp, value));
	value = 0;
	printf("Verificam front %d\n", front(sp, &value));
	printf("%lf\n", value);
	value = 3;
	printf("Verificam dpush_back %d\n", push_back(sp, value));
	value = 1;

	printf("Verificam back %d\n", back(sp, &value));
	printf("%0.lf\n", value);
	print(sp);
	pop_front(sp);
	double v1, v2;

	printf("Verificam back si front %d %d\n", back(sp, &v1), front(sp, &v2));
	printf("Valori: %0.lf %0.lf\n", v2, v1);
	print(sp);

	push_back(sp, 12);
	push_back(sp, 2);
	push_front(sp, 14);
	push_front(sp, 24);
	print(sp);
	front(sp, &value);
	back(sp, &v2);
	printf("%0.lf %0.lf\n",value, v2 );
}
