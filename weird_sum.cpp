#include<bits/stdc++.h>
using namespace std;

long long int dp[1005][10005], n,k,m;

long long int rec(vector<long long int>& a, int i = 1, int j=0)
{
	if(i > k)
		return 0;
	if(j >= n)
		return -1e18;
	if(dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = max(rec(a,i,j+1),rec(a,i+1,j+1)+a[j]*(i%m));
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>k>>m;
	vector<long long int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<rec(v)<<'\n';
}
