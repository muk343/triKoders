#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int sum = 0;

struct tree
{
	tree* left;
	tree* right;
	int data;
	int sum;
};

void inOrder(tree* root)
{
	if(root == NULL)
		return;
	else
	inOrder(root->right);
	root->sum = sum;
	sum+=root->data;
	cout<<"data of root"<<root->data<<" "<<"sum at root"<<root->sum<<"\n";
	inOrder(root->left);
}

tree* createTree(int value)
{
	tree* root = (tree*) malloc(sizeof(tree));
	root->right = NULL;
	root->left = NULL;
	root->data = value;
	return root;
}

void insert(tree* root,int value)
{
	
	if(value<root->data)
	{
		if(root->left!=NULL)
			insert(root->left,value);
		else
			{	tree* newNode = (tree*)malloc(sizeof(tree));
				newNode->right = NULL;
				newNode->left = NULL;
				newNode->data = value;
				root->left = newNode;
			}
		
	}
	if(value>root->data)
	{
		if(root->right!=NULL)
			insert(root->right,value);
		else
			{	tree* newNode = (tree*)malloc(sizeof(tree));
				newNode->right = NULL;
				newNode->left = NULL;
				newNode->data = value;
				root->right = newNode;
			}
		
	}
	
	return ;
}

int main() {
	// your code goes here
	tree* root ;
	root = createTree(7);
	
	insert(root,5);
	insert(root,9);
	insert(root,2);
	insert(root,3);
	insert(root,10);
	
	inOrder(root);
	
	return 0;
}
