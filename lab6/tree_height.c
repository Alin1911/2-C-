#include <stdio.h>
#include <stdlib.h>
// calculeaza doar inaltimea arborelui
typedef struct bst_node {
double value ;
struct bst_node * parent ;
struct bst_node * left ;
struct bst_node * right ;
} bst_node_t ;

 
int binary_tree_height(const bst_node_t* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 

       int lDepth = binary_tree_height(node->left); 
       int rDepth = binary_tree_height(node->right); 
  
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
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

void inOrderPrint(bst_node_t **root)
{
	if (*root)
	{
		inOrderPrint(&(*root)->left);
		printf("%0.f ", (*root)->value);
		inOrderPrint(&(*root)->right);
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
    int a =binary_tree_height(root);
    printf("inaltimea este= %d\n",a);

    return 0;
}