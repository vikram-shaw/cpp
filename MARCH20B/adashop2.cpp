#include<bits/stdc++.h>
using namespace std;

set<pair<int,int>> s;
vector<pair<int,int>> result;
pair<int,int> moves[] = {{1,1},{1,-1},{-1,-1},{-1,1}};

bool bfs(int r, int c, int pr, int pc)
{
	if(r>8 || c>8 || r<1 || c<1)
		return false;
	if(s.find({r,c})!=s.end())
		return false;
	result.push_back({r,c});
	//cout<<r<<" "<<c<<'\n';
	s.insert({r,c});
	bool atleast = false;
	for(int i=0;i<4;i++)
	{
		if(bfs(moves[i].first + r, moves[i].second + c, r, c))
			atleast = true;
	}
	if(!atleast)
	{
		if(s.size()==32)
			return true;
		//cout<<pr<<" "<<pc<<'\n';
		result.push_back({pr,pc});
	}
	return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		bfs(r,c,r,c);
		cout<<result.size()-1<<'\n';
		for(int i=1;i<result.size();i++)
			cout<<result[i].first<<' '<<result[i].second<<'\n';
		s.clear();
		result.clear();
	}
}
