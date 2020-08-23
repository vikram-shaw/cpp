#include<bits/stdc++.h>
using namespace std;

long long int dp[1005][10005], n,k,m;

long long int rec(vector<long long int>& a, int i = 1, int j=0)
{
	for(int i=k;i>=1;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(i > k)
				dp[i][j] = 0;
			else if(j >= n)
				dp[i][j] = -1e18;
			else
				dp[i][j] = max(dp[i][j+1],dp[i+1][j+1]+a[j]*(i%m));
		}
	}
	return dp[1][0];
}

int main()
{
	cin>>n>>k>>m;
	vector<long long int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<rec(v)<<'\n';
}
