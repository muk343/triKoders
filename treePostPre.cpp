#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>


using namespace std;

vector<int> arr;
vector<int> arrCopy;
int keyIndex;

struct _tree;
typedef struct _tree tree;
typedef struct _tree
{
	int node;
	tree* right;
	tree* left;
};

void printPostOrder(tree* root)
{
    
    if(root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->node<<endl;
    return;
}

int find(int low,int high,int key)
{
	int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arrCopy[mid] == key)
            return mid;
        else if(key<arrCopy[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    
    return -1;
}

tree* buildTree(int low,int high)
{
	//if(keyIndex == arr.size()-1)
	if(keyIndex >=arr.size())
	{
		return NULL;
	}
	if(low>high)
		return NULL;
    
    tree* newNode;
    if(high == low)
    {
        newNode = (tree*) malloc(sizeof(tree));
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->node = arr[keyIndex++];
        return newNode;
    }
   
    int sortedIndex = find(0,arr.size()-1,arr[keyIndex]);
    if(sortedIndex == -1)
    {	cout<<"Entry Not found for keyIndex"<<keyIndex;
    	exit(1);
    }
    newNode = (tree*) malloc(sizeof(tree));
    newNode->node = arr[keyIndex];
    keyIndex++;
    
    
    newNode->left = buildTree(low,sortedIndex-1);
    /*
    int i;
    for( i=keyIndex;i<arr.size();i++)
    {
        if(arr[i]>arr[keyIndex])
            break;
    }
    if(i==arr.size())
        newNode->right = NULL;
    else
    */
    newNode->right = buildTree(sortedIndex+1,high);
        
    
    
    return newNode;
}

int main() {
	// your code goes here
	
	int temp;
	while((cin>>temp)>0)
	{	
		arr.push_back(temp);
		arrCopy.push_back(temp);
	
	}

	
	sort(arrCopy.begin(), arrCopy.end());
	tree* root = buildTree(0,arr.size()-1);
	printPostOrder(root);
	
	
	
	return 0;
}
