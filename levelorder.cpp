#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

typedef struct node node;

node * newNode(int data){

	node * new_node = (node*) malloc(sizeof(node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void levelOrder(node * root){
	queue < node* > nodeq;
	nodeq.push(root);
	bool spiral = true;
	while( !nodeq.empty() ){

		node * curr = nodeq.front();
		nodeq.pop();
		cout << curr->data << " ";
		if(spiral){
			if(curr->left)
				nodeq.push(curr->left);
			if(curr->right)
				nodeq.push(curr->right);
		}
		else{
			if(curr->right)
				nodeq.push(curr->right);
			if(curr->left)
				nodeq.push(curr->left);
		}
		spiral = !spiral;
	}

	cout << endl ;
	
}

int main(void){

	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);

	printf("Level Order traversal of binary tree is \n");
	levelOrder(root);
	return 0;
}
