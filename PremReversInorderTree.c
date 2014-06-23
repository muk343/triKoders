#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	struct _node* left;
	struct _node* right;
	int ele;
}node;

node* createNode(int elem)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->ele = elem;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void insertInTree(node* root,int elem)
{
	if(root->ele == elem)
		return;
	if(root->ele < elem)
	{
		if(root->right==NULL)
			root->right = createNode(elem);
		else
			insertInTree(root->right,elem);
	}
	else
	{
		if(root->left==NULL)
			root->left = createNode(elem);
		else
			insertInTree(root->left,elem);
	}
	return;
}

void printTree(node* root)
{
	if(root == NULL)
		return;
	printTree(root->left);
	printf("%d\t",root->ele);
	printTree(root->right);
}

int sum = 0;
void sumTree(node* t)
{
	if(t==NULL) 
		return ;
	
	sumTree(t->right);
	
	int temp = t->ele;
	t->ele = sum;
	sum += temp;
	
	sumTree(t->left);
	return;
}

int main() {
	
	int n;
	scanf("%d",&n);
	node* root = NULL;
	int elem,i;
	for(i=0; i<n; i++)
	{
		scanf("%d",&elem);
		if(root == NULL)
			root = createNode(elem);
		else
			insertInTree(root, elem);
	}
	printf("Printing Tree:\n");
	printTree(root);
	printf("\n");
	printf("After Reversal called:\n");
	sumTree(root);
	printTree(root);
	return 0;
}
