#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;

size_t length(node *list){
	struct node *current=list;
	int count=0;
	while(current->next!=NULL){
		current=current->next;
		count++;
	}
	free(current);
	return count;
}

size_t count(node *list, int value){
	struct node *current=list;
	int count=0;
	while(current->next!=NULL){
		if(current->value==value){
			count++;
			current=current->next;
 		}else{
			current=current->next;
		}
	}
	free(current);
	return count;
}

int push(node **list, int value){
	struct node *new;
        new=(struct node *) malloc(sizeof(struct node));
        if(new==NULL)
                return -1;
	new->value=value;
	new->next=*list;
	*list=new;
	return 0;
}

int pop(node **list){
	int n;
	struct node *temp=(struct node*)*list;
	n=(*list)->value;
	*list=(*list)->next;
	free(temp);
	return n;
	
}

void free_list(node *list){
	while(list!=NULL){
                struct node* temp=list;
                list=list->next;
                free(temp);
        }
}

int main (int argc, char *argv[]){
	return 0;
}
