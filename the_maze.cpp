/*
5 5
0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0
0 4
4 4

true

*/

#include<bits/stdc++.h>
using namespace std;

class Solutions
{
	public:
	bool hasPath(vector<vector<int>>& maze,vector<int>& start,vector<int>& destination)
	{
		int dirx[] = {1,-1,0,0};
		int diry[] = {0,0,1,-1};
		int row = maze.size();
		int col = maze[0].size();
		vector<vector<bool>> visited(row,vector<bool> (col,false));
		queue<vector<int>> qu;
		qu.push(start);
		visited[start[0]][start[1]] = true;
		while(!qu.empty())
		{
			vector<int> curr = qu.front();
			qu.pop();
			if(curr[0] == destination[0] && curr[1] == destination[1])
				return true;
			for(int i=0;i<4;i++)
			{
				curr[0]+=dirx[i];
				curr[1]+=diry[i];
				while(curr[0]+dirx[i]>=0 && curr[1]+diry[i]>=0 && curr[0]+dirx[i]<row && curr[1]+diry[i]<col && !maze[curr[0]][curr[1]])
				{
					curr[0]+=dirx[i];
					curr[1]+=diry[i];
				}
				curr[0]-=dirx[i];
				curr[1]-=diry[i];
				if(!visited[curr[0]][curr[1]])
				{
					qu.push(curr);
					visited[curr[0]][curr[1]] = true;
				}
			}
		}
		return false;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n,vector<int> (m,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>v[i][j];
	vector<int> s(2),d(2);
	cin>>s[0]>>s[1]>>d[0]>>d[1];
	Solutions sol;
	cout<<sol.hasPath(v,s,d)<<'\n';
}


