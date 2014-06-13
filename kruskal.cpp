#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct
{
	int vertex1;
	int vertex2;
	int weight;
}info;

class myComp
{
	public:
	bool operator()(const info& a,const info& b)
	{
		return (a.weight>b.weight);
	}	
};


int main() {
	// your code goes here
	int numVertices,numEdges;
	cin>>numVertices;
	vector<vector<info> > graph;
	graph.resize(numVertices);
	info tempInfo;
	priority_queue<info, vector<info>, myComp> q;
	
	for(int i=0;i<numVertices;i++)
	{
		cin>>numEdges;
		graph[i].resize(numEdges);
		tempInfo.vertex1 = i;
		for(int j=0;j<numEdges;j++)
		{
		//	cin>>tempInfo.vertex1;
			cin>>tempInfo.vertex2;
			cin>>tempInfo.weight;
		}
		graph[i].push_back(tempInfo);
		q.push(tempInfo);
		
	}
	
	int isVisited[numVertices];
	memset(isVisited,0,sizeof(isVisited));
	
	int m=0;
	while(m<numVertices-1)
	{
		if(q.empty())
		{
			cout<<"queue is empty\n";
			exit(1);
		}
		tempInfo = q.top();
		q.pop();
		if(isVisited[tempInfo.vertex1]==0&&isVisited[tempInfo.vertex2]==0 )
		{
			m++;
			cout<<"edge included between vertex "<<tempInfo.vertex1<<" and "<<tempInfo.vertex2<<"having weight "<<tempInfo.weight<<"\n";
		}
	}
	
	return 0;
}
