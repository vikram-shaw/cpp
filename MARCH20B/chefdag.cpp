#include<bits/stdc++.h>
using namespace std;

void bfs(vector<set<int>>& adj, vector<bool>& visited, int i, vector<int>& result, vector<int>& indegree)
{
	for(int n: adj[i])
	{
		indegree[n]--;
		if(indegree[n]==0)
		{
			visited[n] = true;
			result[i] = n;
			bfs(adj, visited, n, result, indegree);
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<set<int>> adj(n+1);
		vector<int> indegree(n+1);
		for(int i=1;i<=k;i++)
		{
			vector<int> rd(n+1);
			for(int j=1;j<=n;j++)
				cin>>rd[j];
			for(int j=1;j<n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					if(adj[rd[j]].find(rd[l]) == adj[rd[j]].end())
						indegree[rd[l]]++;
					adj[rd[j]].insert(rd[l]);
				}
			}
		}
		vector<int> result(n+1);
		vector<bool> visited(n+1);
		for(int i=1;i<=n;i++)
		{
			if(indegree[i]==0 && !visited[i])
			{
				result[i] = 0;
				visited[i] = true;
				bfs(adj, visited, i, result, indegree);
			}
		}
		for(int i=0;i<=n;i++)
			cout<<result[i]<<' ';
		cout<<'\n';
	}
}
