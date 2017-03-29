#include <stdio.h>
#include <stdlib.h>

typedef struct node {
      int value; /* valeur du nœud */
      struct node *next; /* pointeur vers l’élément suivant */
} node;

void reverse(node **list){
	struct node* current = *list;
	struct node* n=NULL;
	while(current!=NULL){
		struct node* temp=current->next;
		current->next=n;
		n=current;
		current=temp;
	}
	*list=n;
}

node *append(node *a, node *b){
	if(a==NULL)
	    return b;
	struct node *res = a;
	struct node *current =res;
	while(current->next!=NULL){
      		current=current->next;
	}
	current->next=b;
	return res;
}

void split(node *list, node **first_half, node **second_half){
	struct node* current = list;
	int size=0;
	while(current!=NULL){
		++size;
		current=current->next;
	}
	current=list;
	struct node* temp=current;
	size=size/2;
	while(size!=0){
		current=current->next;
		--size;
	}
	*second_half=current->next;
	current->next=NULL;
	*first_half=temp;
	list=NULL;
}

