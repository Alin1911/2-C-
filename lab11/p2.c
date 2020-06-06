#include <stdio.h> 
#include <stdlib.h>

typedef struct graf {
    int n;
    int **mat;
} graf;


int min(int *val, int *vect,int n) 
{ 
    int min = 999, min_i; 
    for (int i = 0; i < n; i++) 
        if (vect[i] == 0 && val[i] < min) 
            min = val[i], min_i = i; 
    return min_i; 
} 
  
void prim(graf *ana) 
{ 
    int parent[ana->n],val[ana->n],minim,vect[ana->n]; 
    parent[0] = -1;
    for (int i = 0; i < ana->n; i++){
        val[i] = 999;
        vect[i] = 0; 
    }
    val[0] = 0; 

    for (int i = 0; i < ana->n - 1; i++) { 
        minim = min(val, vect,ana->n); 
        vect[minim] = 1; 
        for (int j = 0; j < ana->n; j++) 
            if ((ana->mat)[minim][j] != 0 && !(vect[j])) 
                if((ana->mat)[minim][j] < val[j])
                    parent[j] = minim, val[j] = (ana->mat)[minim][j]; 
    }
 
    printf("arbore  cost\n"); 
    for (int i = 1; i < ana->n; i++) 
        printf("%d---%d \t%d \n", parent[i]+1, i+1, (ana->mat)[i][parent[i]]); 
} 

void main() 
{ 
    int n,m,k,cos;
    struct graf *ana=malloc(sizeof(*ana));
    printf("Nr de noduri \n");
    scanf("%d",&n);
    (ana->mat) = (int **)malloc(sizeof(int *)*n);
    for (int i = 0; i < n; i++){
        (ana->mat)[i] = (int *)malloc(sizeof(int)*n);
    }
    ana->n=n;
    printf("Introdu muchii exemplu 1-2 cost 3(1 2 3) \n");
    scanf("%d%d%d",&m,&k,&cos);
    printf("Introdu muchii ex(2 3 4), introdu negativ pentru a te opri(-1 -1 -1)\n");
    while(m>=0 && k>=0 && m<=n && k<=n){
        (ana->mat)[m-1][k-1]=cos;
        (ana->mat)[k-1][m-1]=cos;
        scanf("%d%d%d",&m,&k,&cos);
    }
    prim(ana); 
} 
