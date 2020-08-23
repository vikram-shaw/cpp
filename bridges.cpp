#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
#define INF int(1e9+5)

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,int>> v(n);
		for(pair<int,int>& p: v)
			scanf("%d",&p.first);
		for(pair<int,int>& p: v)
			scanf("%d",&p.second);
		sort(v.begin(),v.end(),[](const pair<int,int>& p1, const pair<int,int>& p2){
			if(p1.second != p2.second)
				return p1.second < p2.second;
			return p1.first < p2.first;
		});
		vector<int> dp(n,1);
		int res = 0;
		for(int j=1;j<n;j++)
		{
			for(int i=0;i<j;i++)
			{
				if(v[i].first < v[j].first)
				{
					dp[j] = max(dp[i]+1,dp[j]);
				}
			}
		}
		for(int x: dp)
			res = max(res,x);
		cout<<res<<endl;
	}
}
