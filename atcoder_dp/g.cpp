#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int incoming[MAX];
int dist[MAX];
bool visited[MAX];

void bfs(vector<vector<int>>& adj, int p)
{
	visited[p] = true;
	for(int c: adj[p])
	{
		dist[c] = max(dist[c], dist[p] + 1);
		incoming[c]--;
		if(incoming[c] == 0)
			bfs(adj,c);
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1,vector<int>());
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		incoming[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i] && incoming[i] == 0)
			bfs(adj,i);
	}
	int res = 0;
	for(int i=1;i<=n;i++)
		res = max(res, dist[i]);
	cout<<res<<'\n';
}
