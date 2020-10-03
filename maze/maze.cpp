#include<bits/stdc++.h>
using namespace std;

set<pair<pair<int,int>,pair<int,int>>> visited;

string str = "";

bool bfs(vector<vector<int>>& maze, int u, int v, int pu, int pv)
{
	if(u<0 || u>12 || v<0 || v>11){
		return false;
	}
	if(u==2 && v==0)
	{
		cout<<"target reached"<<endl;
		return true;
	}
	if(maze[u][v]==1){
		return false;
	}
	if(visited.find(make_pair(make_pair(pu,pv),make_pair(u,v)))!=visited.end())
		return false;
	visited.insert(make_pair(make_pair(pu,pv),make_pair(u,v)));
	if(pv + 1 == v){			//coming from downwards
		if(bfs(maze,u,v+1,u,v))
		{
			str = "u" + str;
			return true;
		}
		if(bfs(maze,u+1,v,u,v))
		{
			str = "r" + str;
			return true;
		}
	}
	else if(pu + 1 == u){		//coming from left
		if(bfs(maze,u+1,v,u,v))
		{
			str = "r" + str;
			return true;
		}
		if(bfs(maze,u,v-1,u,v))
		{
			str = "d" + str;
			return true;
		}
	}
	else if(pv - 1 == v){		//coming from upward
		if(bfs(maze,u,v-1,u,v))
		{
			str = "d" + str;
			return true;
		}
		if(bfs(maze,u-1,v,u,v))
		{
			str = "l" + str;
			return true;
		}
	}
	else if(pu - 1 == u){		//coming from right
		if(bfs(maze,u-1,v,u,v))
		{
			str = "l" + str;
			return true;
		}
		if(bfs(maze,u,v+1,u,v))
		{
			str = "u" + str;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	vector<vector<int>> maze(13,vector<int> (12));
	for(int i=0;i<=12;i++)
		for(int j=0;j<=11;j++)
			cin>>maze[i][j];
	bfs(maze,10,0,10,-1);
	cout<<str<<endl;
}
