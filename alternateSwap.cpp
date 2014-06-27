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

node* swap(node* head)
{
	if(head == NULL || head->next == NULL)
		return head;
	node* temp = head->next->next;
	head->next->next = head;
	node* headTemp;
	headTemp = head->next;
	head->next = temp;
	head = headTemp;
	node* itr = head->next;
	//cout<<itr->val<<"is the value\n";
	
	while(temp!=NULL)
	{
		if(temp->next == NULL)
			return head;
		node* temp2 = temp->next->next;
		itr->next = temp->next;
		temp->next->next  = temp;
		temp->next= temp2;
		itr=itr->next->next;
		temp = itr->next; 
	}
	
	return head;
	
}

int main() {
	// your code goes here
	node* head;
	head = NULL;
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,3);
	head = insert(head,4);
	head = insert(head,5);
	head = insert(head,6);
	head = insert(head,7);
	head = insert(head,8);
	head = insert(head,9);
	head = insert(head,10);
	head = insert(head,11);
	
	
	print(head);
	node* temp = head->next;
	head->next = NULL;
	head = reverse(temp,head);
	print(head);
	head = swap(head);
	print(head);
	return 0;
}

