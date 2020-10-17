#include<bits/stdc++.h>
using namespace std;

int sum[(1<<21)];
int dp[(1<<21)][20];
int mx = ((1<<20)-1);

int rec(int n, int i)
{
	if(i == -1)
		return sum[n];
	if(dp[n][i]!=-1)
		return dp[n][i];
	if(((n>>i)&1))
		return dp[n][i] = rec(n-(1<<i),i-1)+rec(n,i-1);
	return dp[n][i] = rec(n,i-1);
}
int main()
{
	
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		sum[v[i]]++;
	}
	int result = 0;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		result += rec(mx^v[i],19);
	}
	cout<<result<<'\n';
}

