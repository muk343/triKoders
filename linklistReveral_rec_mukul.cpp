#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int val;
	node* next;
};

node* insert(node* head, int val)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = val;
	newNode->next = head;
	return newNode;
}

void print(node* head)
{
	
	node* temp;
	temp = head;
	while(temp!=NULL)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

node* reverse(node* head, node* pointTo)
{
	if(head == NULL)
		return pointTo;
	node* temp  = head->next;
	head->next = pointTo;
	return reverse(temp,head);
}

int main() {
	// your code goes here
	node* head;
	head = NULL;
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,3);
	head = insert(head,4);
	
	print(head);
	node* temp = head->next;
	head->next = NULL;
	head = reverse(temp,head);
	print(head);
	return 0;
}
