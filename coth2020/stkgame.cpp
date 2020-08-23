#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
long long a[MAX], h[MAX];
map<pair<long long, long long>,long long> dp;

long long rec(long long n, long long pre)
{
	if(n == 0)
		return 0;
	if(dp.count({n,pre}))
		return dp[{n,pre}];
	if(a[n] + h[n] < pre && a[n] - h[n] > a[n-1])
		return dp[{n,pre}] = 1 + max(rec(n-1,a[n]),rec(n-1,a[n]-h[n]));
	if(a[n] + h[n] < pre)
		return dp[{n,pre}] = 1 + rec(n-1,a[n]);
	if(a[n] - h[n] > a[n-1])
		return dp[{n,pre}] = 1 + rec(n-1,a[n]-h[n]);
	return dp[{n,pre}] = rec(n-1,a[n]);
}

int main()
{
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>h[i];
	a[0] = LONG_LONG_MIN;
	cout<<rec(n,LONG_LONG_MAX)<<'\n';
}
