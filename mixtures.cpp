#include <iostream>
#include <vector>

using namespace std;
#define INF 100000000

int main()
{
	int n;
	while((cin>>n)>0)
	{
		if(n==1)
		{
			cin>>n;
			cout<<"0\n";
			continue;
		}
		vector<vector<int> >smoke;
		vector<vector<int> >col;
		vector<int> inp;
		smoke.resize(n);
		col.resize(n);
		inp.resize(n);
		
		for(int i=0;i<n;i++)
		{
			col[i].resize(n);
			smoke[i].resize(n);
		}	
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				{
					col[i][j] = 0;
					smoke[i][j]= 0;
				}
			
		for(int i=0;i<n;i++)
		{
			cin>>inp[i];
			smoke[i][i] = 0;
			col[i][i] = inp[i];
		}
		
		for(int len = 2; len<=n;len++)
			for(int i=0;(i+len-1)<n;i++)
			{
				int j= i+len-1;
				int min = INF;
				for(int k=i ; k<j;k++)
				{
					if((smoke[i][k]+smoke[k+1][j] + col[i][k]*col[k+1][j]) < min)
					{
						min = (smoke[i][k]+smoke[k+1][j] + col[i][k]*col[k+1][j]);
						col[i][j] = (col[i][k] + col[k+1][j])%100;
					}
				}
				smoke[i][j] = min;
			}
		
		cout<<smoke[0][n-1]<<"\n";
		
		
	}
	
	return 0;
	
}
