#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> rd(n);
	for(int &x: rd)
		scanf("%d",&x);
	vector<int> dp(n,INF);
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=i+k && j<n;j++)
		{
			dp[j] = min(dp[j],dp[i]+abs(rd[i]-rd[j]));
		}
	}
	cout<<dp[n-1]<<'\n';
}
