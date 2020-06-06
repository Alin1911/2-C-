#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	double data;
	struct node *prev;
	struct node *next;
}node_t;

void push_back(node_t **head, node_t *new_node)
{
	double val;
	printf("valoare la final : ");
	scanf("%le", &val);
	new_node = (node_t *) malloc (sizeof(node_t));
	node_t *last = (*head);
	new_node->data = val;
	new_node->next = NULL;
	if ((*head) == NULL)
	{
		new_node->prev = NULL;
		(*head) = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

void push_front(node_t **head, node_t *new_node)
{
	double val;

	printf("valoare la inceput : ");
	scanf("%le", &val);

	new_node = (node_t *) malloc (sizeof(node_t));

	new_node->data = val;
	new_node->next = (*head);
	new_node->prev = NULL;

	if ((*head) == NULL)
	{
		((*head)->prev = new_node);
	}

	(*head) = new_node;
}

void push_after(node_t *current, node_t *new_node)
{	
	node_t *temp = current;
	node_t *p = current;
	double val;
	int pos, contor = 1, i = 1;
	printf("valoare ");
	scanf("%le", &val);
	new_node = (node_t *) malloc (sizeof(node_t));
	printf("dupa ce nod ?: ");
	scanf("%d", &pos);
	new_node->data = val;
	new_node->next = NULL;
	new_node->prev = NULL;
	while (i < pos)
	{
		p = p->next;
		i++;
	}
	while (contor < pos - 1)
	{
		temp = temp->next;
		contor++;
	}
	temp = temp->next;
	new_node->next = temp->next;
	p->prev = new_node;
	temp->next = new_node;
	new_node->prev = temp;
}

void print(node_t *head)
{
	while (head != NULL)
	{
		printf("%.0f ", head->data);
		head = head->next;
	}
	printf("\n");
} 

int main()
{
	node_t *head = NULL;
	node_t *new_node;

	push_back(&head, new_node);
	push_back(&head, new_node);
	push_back(&head, new_node);
	push_front(&head, new_node);
	push_back(&head, new_node);
	push_front(&head, new_node);
	push_back(&head, new_node);
	push_back(&head, new_node);
	push_front(&head, new_node);
	push_after(head, new_node);
	print(head);
	free(head);
}