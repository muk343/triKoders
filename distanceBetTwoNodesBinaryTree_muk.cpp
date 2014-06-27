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

int getDistance(tree* root, int val)
{
	if(root->data == val)
		return 0;
	if(root->data <val)
	{
		return (1+getDistance(root->right,val));
	}
	if(root->data >val)
	{
		return (1+getDistance(root->left,val));
	}
}

int findMin(tree* root, int val1,int val2)
{
	if(root->data==val1)
	{
		return getDistance(root,val2);
	}
	else if(root->data==val2)
	{
		return getDistance(root,val1);
	}
	
	else if(root->data >val1 && root->data>val2)
	{
		return findMin(root->left,val1,val2);
	}
	else if(root->data <val1 && root->data<val2)
	{
		return findMin(root->right,val1,val2);
	}
	else
	{
		return (getDistance(root,val1)+ getDistance(root,val2));
	}
}

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
	root = createTree(4);

	insert(root,2);
	insert(root,1);
	insert(root,3);
	insert(root,7);
	insert(root,8);
	insert(root,5);
	insert(root,6);
//	inOrder(root);
	cout<<findMin(root,1,6);
	return 0;
}
