#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node {
	int data;
	struct node * next;
};

typedef struct node node;

void removeLoop(node * loop_node , node * head);

void push(node ** head_ref,int num){
	node * temp = (node*) malloc(sizeof(node));
	temp->data = num;
	if( *head_ref == NULL){
		*head_ref = temp;
		temp->next = NULL;
	}
	else{
		temp->next = *head_ref;
		*head_ref = temp;
	}
}

void reverse(node ** head_ref){

	node * prev = NULL;
	node * current = (*head_ref);
	node * next;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref  = prev;
}

node *  reverse_group(node * head_ref,int k){

	node * prev = NULL;
	node * current = (head_ref);
	node * next;
	int temp = k;
	while(current!=NULL && temp > 0 ){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		temp--;
	}
	if(next!=NULL)
		head_ref->next = reverse_group(next,k);

	return prev;
}

void traverse(node * head_ref){
	node * temp = head_ref;
	while(temp!=NULL){
		cout << temp->data << " " ;
		temp = temp->next;
	}
	cout << endl;
}

int detectAndRemoveLoop(node * head_ref){
	node * slow_p = head_ref;
        node * fast_p = head_ref;
	while( slow_p && fast_p && fast_p->next){
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if(slow_p == fast_p){

			removeLoop(slow_p,head_ref);
			return 1;
		}
	}
	return 0;
}

void removeLoop(node * loop_node , node * head){
	node * ptr1 = loop_node;
	node * ptr2 = loop_node;
	int k = 0;
	while(ptr1->next != ptr2){
		ptr1= ptr1->next;
		k++;
	}

	/* first */
	ptr1 = head;

	/* second */
	ptr2 = head;

	for(int i=0;i<k;i++)
		ptr2 = ptr2->next;

	while(ptr2->next != ptr1){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	ptr2 = ptr2->next;

	while(ptr2->next != ptr1)
		ptr2 = ptr2->next;

	ptr2->next = NULL;
}


int main(void){

	node * head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15); 
	push(&head, 85);      
	push(&head, 3);      
	push(&head, 7);      

	traverse(head);    
	reverse(&head);                      

	printf("\n Reversed Linked list \n");
	traverse(head);

	cout << "Reverse in groups !: " << endl;
	node * new_head = reverse_group(head,3);
	traverse(new_head);

	node * head2 = NULL;
	push(&head2, 5);
	push(&head2, 4);
	push(&head2, 3);
	push(&head2, 2);
	push(&head2, 1);

	head2->next->next->next->next->next = head2->next->next;
	int res = detectAndRemoveLoop(head2);
	if(res){
		cout << "Loop Detected" << endl;
		traverse(head2);
	}

	return 0;


}

