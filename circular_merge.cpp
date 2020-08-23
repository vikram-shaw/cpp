#include<bits/stdc++.h>
using namespace std;

long long dp[805][805],pre[805];
int n;
const long long INF = (long long) 1e18;

long long sum(int l, int r)
{
	return pre[r+1] - pre[l];
}

long long rec(int l, int r, vector<long long>& circle)
{
	if(dp[l][r] != -1)
		return dp[l][r];
	if(l == r)
		return 0;
	if(l+1 == r)
		return circle[l] + circle[r];
	long long res = INF;
	for(int i=l;i<r;i++)
		res = min(res,rec(l,i,circle)+rec(i+1,r,circle));
	return dp[l][r] = res + sum(l,r);
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n;
	int size = 2*n;
	vector<long long> circle(size+1);
	for(int i=0;i<n;i++)
	{
		cin>>circle[i];
		circle[i+n] = circle[i];
	}
	pre[0] = 0;
	for(int i=1;i<=size;i++)
		pre[i] = pre[i-1] + circle[i-1];
	
	long long res = 1e18;
	for(int i=0;i<=n;i++)
	{
		long long curr = rec(i,i+n-1,circle);
		res = min(res,curr);
	}
	cout<<res<<'\n';
}
