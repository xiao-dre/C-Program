#include<stdio.h>
#include<stdlib.h>

struct data{
	int value;
	struct data *right,*left;
}*root= NULL;

struct data *createNewNode(int value){
	//Membuat Node dari kerangka yang kita buat
	//Factory
	struct data *curr = (struct data *) malloc(sizeof(struct data));
	curr->value = value;
	curr->left=curr->right=NULL;
	return curr;
};

struct data *insert (struct data *root,int value){
	if(root==NULL){
		root=createNewNode(value);
		
	}
	else if(value < root->value){
		root->left=insert(root->left,value);
	}
	else if(value > root->value){
		root->right=insert(root->right,value);
	}
	else{
		printf("ERROR\n");
	}
	return root;	
}

int search (struct data *root,int value) {
	if(root==NULL){
		return -1;
	}
	else if(value < root->value){
		search(root->left,value);
	}
	else if(value > root->value){
		search(root->right,value);
	}
	else {
		return 1;
	}	
}

void inOrder(struct data *root) {
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	printf("%d ",root->value);
	inOrder(root->right);
}

int main() {
    root = insert(root, 18);
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 17);
    inOrder(root);
}