#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
double value ;
struct bst_node * parent ;
struct bst_node * left ;
struct bst_node * right ;
} bst_node_t ; 

void removes( bst_node_t **root , const double value ) { 
    if (*root == NULL) return;
    if (value < (*root)->value) 
         removes(&(*root)->left, value); 
    else if (value > (*root)->value) 
         removes(&((*root)->right), value); 
    else {
        if ((*root)->left == NULL) 
        { 
            bst_node_t  *temp = (*root)->right;
            *root = temp; 
        } 
        else if ((*root)->right == NULL) 
        { 
            bst_node_t  *temp = (*root)->left; 
            *root = temp;
        }
    }
} 


bst_node_t* search(bst_node_t** root, double val) 
{
    if(!(*root)) 
        return NULL;
    if(val == (*root)->value) 
        return *root;
    else if(val < (*root)->value) 
        search(&((*root)->left), val);
         else if(val > (*root)->value)
            search(&((*root)->right), val);
}

void insert(bst_node_t ** root, double val) 
{
    bst_node_t *temp = NULL;
    if(!(*root))
    {
        temp = malloc(sizeof(bst_node_t));
        temp->left = temp->right = NULL;
        temp->value = val;
        *root = temp;
        return;
    }
    if(val < (*root)->value) 
        insert(&(*root)->left, val);
    else if(val > (*root)->value) 
                insert(&(*root)->right, val);
            
}

void print(bst_node_t **root) {
    if (*root)
    {
        print(&(*root)->left);
        printf("%0.f ", (*root)->value);
        print(&(*root)->right);
    }
}

 void main() {
    double x;
    bst_node_t *find;
    bst_node_t *root=malloc(sizeof(bst_node_t));
    scanf("%lf",&x);
    while(x!=0){
        scanf("%lf",&x);
        insert(&root,x);
    }
    print(&root);
    printf("cauta numarul\n");       
    scanf("%lf", &x);        
    find = search(&root,x);
    printf(" %0.f exists \n", find->value);
    printf("sterge numarul:\n");
    scanf("%lf", &x); 
    removes(&root, x);      
    print(&root);

}