#include<bits/stdc++.h>
using namespace std;

class com{
	public:
	bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
		return p1.second > p2.second;	//smaller value according to second value
	}
};

void solve()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	priority_queue<pair<int,int>,vector<pair<int,int>>,com> pq[n+1];
	map<int,int> map[n+1];
	for(int i=1;i<=n;i++) //i denoting the question number
	{
		for(int j=1;j<=m;j++) //j denoting the options
		{
			map[i][j]++;
			pq[i].push({j,1});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			int r;
			scanf("%d",&r);
			int res = map[i][r]++;
			vector<pair<int,int>> tem;
			while(!pq[i].empty())
			{
				tem.push_back(pq[i].top());
				pq[i].pop();
			}
			for(int l=0;l<tem.size();l++)
			{
				if(tem[l].first == r && tem[l].second == res)
					pq[i].push({r,res+1});
				else
					pq[i].push(tem[l]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<pq[i].top().first<<' ';
	puts("");
}

int main()
{
    int t;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",t);
        solve();
	}
}
