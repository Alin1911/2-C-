#include<stdio.h>
#include<stdlib.h>

typedef int T;

typedef struct nod {
	T val; 
	struct nod *leg;
	} Nod;

void push_front(Nod **sp, int x) { 
	Nod * nou = (Nod*) malloc(sizeof(Nod)); 
	nou->val = x; 
	nou->leg = *sp; 
	*sp = nou;
}

int sum(Nod head, int acc){
	if(head->leg !=NULL)
		return sum(head->leg,acc) + head->val;
	else
		return head->val;
}

void push_back(Nod **st, int x){
	Nod *nou = (Nod*)malloc(sizeof(Nod));
	nou->val=x;
	Nod *p =(*st);
	nou->val=x;
	nou->leg=NULL;
	if (p==NULL){
		(*st)=nou;
		return;
	}

	while(p->leg!=NULL)
		p=p->leg;
	
	p->leg=nou;
}

void cauta_element(Nod *st, int x){
	for(Nod *it=st; it; it=it->leg){
		if(x==it->val)
			printf("da\n");
	}
}

void sum2(Nod *st){
	int s=0;
	for (Nod *it=st; it ; it=it->leg){
		s = s + it->val;
	}
	printf("%d\n",s);
}

void midorg(Nod *st){
	int i = 0;
	for (Nod *it=st; it ; it=it->leg)
		i++;
	Nod *ir=st;
	int a =i / 2;
	for (i=0;i<a-1;i++)
		ir=ir->leg;
	printf("%d\n",ir->val);
	
}
void elimina_element(Nod **sp, int x ){
	for(Nod *it=sp; it ; it= it->leg){
		if(x==it->val)
			break;
	}
	
}

void main(){
	Nod* st=NULL;   
	int i,x;
	scanf("%d",&x);

	for (i=1; i<5; i++){
		push_back(&st,i);
	}
	 
	for (i=5; i<16; i++){
		push_front(&st,i);
	}
 
	for(Nod *it=st; it;it=it->leg){
		printf(" %d",it->val);
	}
	printf("111111\n");
    printf("%d",sum(st,0));
    printf("1111111111\n");
	printf("\n");
	cauta_element(st,x);
	sum2(st);
	midorg(st);
	printf("1\n");
    printf("%d",sum(st,0));
    printf("\n");

}