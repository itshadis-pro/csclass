//11/25/2025

#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int val;
	struct node  *next;
	struct node *prev;

} node;

typedef struct deque {

	struct node *head;
	node *tail;
	int size;

} deque;




deque *create_deque();

void add_to_front(deque *d, int n){


	node *n = malloc(sizeof(node));
	n -> val = n;
	deque->head = n;
}

void add_to_back(deque *d, int n){

	new_node -> val = n;
	deque->tail = new_node;

}

int remove_from_front(deque *d){


	if(head == NULL){

	int var = deque->head->next;
	free(deque -> head);
	deque -> head = var;

	}
}

int remove_from_back(deque *d){

}



