#include<bits/stdc++.h>
using namespace std;

int a[512];
int pre[512];
int n;
const long long INF = (long long)1e18;
long long dp[512][512];
int sum(int l,int r)
{
	return (100 + pre[r+1] - pre[l])%100;
}

long long find(int l,int r)
{
	if(l>=r)
		return 0;
	if(dp[l][r] != -1)
		return dp[l][r];
	if(l+1 == r)
		return dp[l][r] = a[l]*a[r];
	long long res = INF;
	for(int i=l;i<r;i++)
		res = min(res,find(l,i) + find(i+1,r) + sum(l,i)*sum(i+1,r));
	return dp[l][r] = res;
}

int main()
{
	while(cin>>n)
	{
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i==j)
					dp[i][j] = 0;
				else
					dp[i][j] = -1;
		pre[0] = 0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			pre[i+1] = (pre[i] + a[i])%100;
		}
		cout<<find(0,n-1)<<'\n';
	}
}
