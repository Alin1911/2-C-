#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
double value ;
struct bst_node * parent ;
struct bst_node * left ;
struct bst_node * right ;
} bst_node_t ;

int minValue( bst_node_t *node) { 
  bst_node_t* current =node; 
  
  while (current->left != NULL) { 
    current = current->left; 
  } 
  return(current->value); 
} 
int maxValue( bst_node_t* node) { 
   bst_node_t* current = node; 

  while (current->right != NULL) { 
    current = current->right; 
  } 
  return(current->value); 
} 

int isBST( bst_node_t* node) 
{ 
if (node == NULL) 
    return 1; 
    
if (node->left!=NULL && maxValue(node->left) > node->value) 
    return 0; 
    
if (node->right!=NULL && minValue(node->right) < node->value) 
    return 0; 
    
if (!isBST(node->left) || !isBST(node->right)) 
    return 0 ; 
    
return 1; 
} 

void insert(bst_node_t ** tree, double val) 
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
void deltree(bst_node_t * tree) 
{
    if (tree) 
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}
void inOrderPrint(bst_node_t *root)
{
	if (root)
	{
		inOrderPrint(root->left);
		printf("%0.f ",root->value);
		inOrderPrint(root->right);
	}
}

 int main()
{
    double x;
    bst_node_t *root=malloc(sizeof(bst_node_t));
    scanf("%lf",&x);
    while(x!=0){
   		insert(&root,x);
    	scanf("%lf",&x);
    }
    inOrderPrint(root);
    printf("\n");
    if(isBST(root) == 1)  
        printf("da\n"); 
    else
        printf("nu\n");
    return 0;
}