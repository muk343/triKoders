#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue> 
using namespace std;

int main() {
	
	int n,u,v,listSize;
	scanf("%d",&n);
	vector<int> node[n+1];
	int dist[n+1];
	bool *explored = new bool[n+1];
	for(int i=0; i<n-1; i++)
	{
		scanf("%d %d",&u,&v);	
		node[u].push_back(v);
		node[v].push_back(u);
	}

	for(int i=0; i<=n; i++)
	{
		explored[i] = false;
		dist[i] = 0;
	}
	
	if(n == 1)
	{
		printf("0");
		return(0);
	}
	queue<int> q;
	q.push(1);
	explored[1] = true;
	int maxD = -1;
	int maxVertex = -1;
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		listSize = node[v].size();
		for(int i=0; i < listSize; i++)
		{
			u = node[v][i];
			if(!explored[u])
			{
				dist[u] = dist[v] + 1;
				if(maxD < dist[u])
				{
					maxD  = dist[u];
					maxVertex = u;
				}
				q.push(u);
				explored[u] = true;
			}
		}
	}
	
	for(int i=0; i<=n; i++)
	{
		explored[i] = false;
		dist[i] = 0;
	}
		
	
	q.push(maxVertex);
	explored[maxVertex] = true;
	maxVertex = -1;
	maxD = -1;
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		listSize = node[v].size();
		for(int i=0; i < listSize; i++)
		{
			u = node[v][i];
			if(!explored[u])
			{
				dist[u] = dist[v] + 1;
				if(maxD < dist[u])
				{
					maxD  = dist[u];
					maxVertex = u;
				}
				q.push(u);
				explored[u] = true;
			}
		}
	}
	printf("%d",maxD);

	return 0;
}
