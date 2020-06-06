#include <stdio.h> 
#include <stdlib.h>

typedef struct graf {
    int n;
    int **mat;
} graf;


void print(graf *ana){
    int c=0;
     for (int i = 0; i < ana->n; ++i)
    {
        for (int j = 0; j < ana->n; ++j)
        {
            if((ana->mat)[i][j]!=0){
                printf("%d--->%d cost:%d\n",i+1,j+1,(ana->mat)[i][j]);
            }
        }
    }

}


void main() 
{ 
    int n,m,cos,k;
    struct graf *ana=malloc(sizeof(*ana));
    printf("Nr de noduri \n");
    scanf("%d",&n);
    (ana->mat) = (int **)malloc(sizeof(int *)*n);
    for (int i = 0; i < n; i++){
        (ana->mat)[i] = (int *)malloc(sizeof(int)*n);
    }
    ana->n=n;
    printf("numerotarea incepe de la 1 a nodurilor\n");
    printf("Introdu muchii exemplu 1-2 3 \n");
    scanf("%d%d%d",&m,&k,&cos);
    printf("Introdu muchii si cost ex(2-3 3) introdu negativ pentru a te opri(-1 -1)\n");
    while(m>=0 && k>=0 && m<=n && k<=n){
        (ana->mat)[m-1][k-1]=cos;
        scanf("%d%d%d",&m,&k,&cos);
    }

    print(ana);

}
