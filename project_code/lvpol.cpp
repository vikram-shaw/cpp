#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000005];
vector<int> result;
int visited[1000005], size = 1;

void dfs(int p)
{
	for(int c: adj[p])
	{
		if(!visited[c])
		{
			size++;
			visited[c] = true;
			dfs(c);
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
		for(int i=0;i<k;i++)
		{
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int c = 0;
		result.clear();
		size = 1;
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
			{
				c++;
				visited[i] = true;
				dfs(i);
				result.push_back(size);
				size = 1;
			}
		}
		cout<<c<<'\n';
		sort(result.begin(),result.end());
		for(int r: result)
			cout<<r<<' ';
		puts("");
		for(int i=0;i<n;i++)
		{
			adj[i].clear();
			visited[i] = false;
		}
		result.clear();
	}
}
