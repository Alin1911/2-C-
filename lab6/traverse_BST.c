#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst_node { 
 	double value;
 	struct bst_node *parent; 
 	struct bst_node *left; 
 	struct bst_node *right; 
}bst_node_t;

typedef void (*func_t)(bst_node_t* const node); 

void insert(bst_node_t** tree, double val) 
{
    bst_node_t *temp = NULL;
    if(!(*tree))
    {
        temp = malloc(sizeof(bst_node_t));
        temp->left = temp->right = NULL;
        temp->value = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->value) 
        insert(&(*tree)->left, val);
    else if(val > (*tree)->value) 
                insert(&(*tree)->right, val);
            
}


void traverse_pre_order( bst_node_t * const node, func_t func)
{
	if (!node || !func)
		return;
	func(node);
	printf("%0.f ",node->value);
	traverse_pre_order(node->left, func);
	traverse_pre_order(node->right, func);
}
void print_pre_order( bst_node_t * const node)
{
	if (!node)
		return;
	printf("%0.f ",node->value);
	print_pre_order(node->left );
	print_pre_order(node->right );
}


void  traverse_in_order( bst_node_t * const  node, func_t func)
{
	if(!node || !func)
		return;
	traverse_in_order(node->left, func);
	printf("%0.f ",node->value);
	func(node);
	traverse_in_order(node->right, func);
}
void print_in_order( bst_node_t * const node)
{
	if (!node)
		return;
	print_in_order(node->left );
	printf("%0.f ",node->value);
	print_in_order(node->right );
}



void traverse_post_order( bst_node_t * const node, func_t func)
{
	if (!node || !func)
		return;
	traverse_post_order(node->left, func);
	traverse_post_order(node->right, func);
	printf("%0.f ",node->value);
	func(node);
}
void print_post_order( bst_node_t * const node)
{
	if (!node)
		return;
	print_post_order(node->left );
	print_post_order(node->right );
	printf("%0.f ",node->value);
}

void inOrderPrint(bst_node_t **root)
{
	if (*root)
	{
		inOrderPrint(&(*root)->left);
		printf("%0.f ", (*root)->value);
		inOrderPrint(&(*root)->right);
	}
}



void main(){
	double x;
	func_t *func;
    bst_node_t *root=malloc(sizeof(bst_node_t));
    scanf("%lf",&x);
    while(x!=0){
    
    	if (x !=0)
    		insert(&root,x);
    	scanf("%lf",&x);
    }
    //traverse_post_order(root,func);
    printf("intra la cod sa vezi ca am si cu aplicarea functiei\n");
    printf("Post_order\n");
    print_post_order(root);
    printf("\n");
    printf("In_order\n");
    print_in_order(root);
    printf("\n");
    printf("Pre_order\n");
    print_pre_order(root);
    printf("\n");

}