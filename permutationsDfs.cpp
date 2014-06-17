#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


vector<int> isVisited;
int n;
vector<char> all;


void print(vector<char> all)
{
	for(int i=0;i<all.size();i++)
		cout<<all[i];
}

void dfs(int index)
{
	all.push_back((char)('0'+index+1));
	isVisited[index] = 1;
	int flag =0;
	for(int i=0;i<n;i++)
	{
		if(isVisited[i])
			continue;
		//print(all);
		//cout<<index+1;
		flag = 1;
		dfs(i);
		all.pop_back();
		isVisited[i] = 0;
	}
	if(flag == 0)
	{
		print(all);
		//cout<<index+1;
		cout<<endl;
	}
}

int main()
{
	
	cin>>n;
	cout<<endl;
	isVisited.resize(n);
	for(int i=0;i<n;i++)
	{
		dfs(i);
		isVisited[i] = 0;
		all.pop_back();
		
	}
}
