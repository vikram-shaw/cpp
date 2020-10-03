#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> dp(3);
	for(int i=0;i<n;i++)
	{
		vector<int> new_dp(3),rd(3);
		for(int &r: rd)
			scanf("%d",&r);
		new_dp[0] = rd[0] + max(dp[1],dp[2]);
		new_dp[1] = rd[1] + max(dp[0],dp[2]);
		new_dp[2] = rd[2] + max(dp[0],dp[1]);
		dp = new_dp;
	}
	cout<<max(dp[0],max(dp[1],dp[2]))<<'\n';
}
