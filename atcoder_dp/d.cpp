#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,w;
	cin>>n>>w;
	vector<long> dp(w+1,0);
	for(int i=0;i<n;i++)
	{
		int weight,value;
		vector<long> new_dp(w+1,0);
		scanf("%d%d",&weight,&value);
		for(int j=1;j<=w;j++)
		{
			if(j>=weight)
				new_dp[j] = max(dp[j],dp[j-weight]+value);
			else
				new_dp[j] = dp[j];
		}
		dp = new_dp;
	}
	printf("%ld\n",dp[w]);
}
