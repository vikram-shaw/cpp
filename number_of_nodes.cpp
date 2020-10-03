#include<bits/stdc++.h>
using namespace std;
int r = 0;
void dfs(vector<vector<int>>& adj, vector<bool>& visited, string& s, set<char>& st, int p = 0)
{
	assert(p>=0);
	for(int i: adj[p])
	{
		if(!visited[i])
		{
			visited[i] = true;
			dfs(adj,visited,s,st,i);
			if(st.find(s[i])==st.end())
			{
				r++;
				st.insert(s[i]);
			}
		}
	}
}

void solve()
{
	int n;
	r = 0;
	string s;
	cin>>n>>s;
	vector<vector<int>> adj(n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> visited(n);
	set<char> st;
	visited[0] = true;
	dfs(adj,visited,s,st);
	if(st.find(s[0])==st.end())
		r++;
	cout<<r<<'\n';
}

int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
}

