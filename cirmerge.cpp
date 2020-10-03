#include<bits/stdc++.h>
using namespace std;

const long long INF = (long long) 1e18;

long long a[512];
long long pre[512];
long long dp[512][512];
int n;

int cir(int x)
{
	return x<n?x:(x+n)%n;
}

long long sum(int l,int r)
{
	if(l<=r)
		return pre[r+1] - pre[l];
	return pre[n] + pre[r+1] - pre[l];
}

long long find(int l,int r)
{
	if(dp[cir(l)][cir(r)]!=-1)
		return dp[cir(l)][cir(r)];
	if(cir(l)==cir(r))
		return 0;
	if(cir(l+1) == cir(r))
		return a[l]+a[r];
	long long res = INF;
	long long s = sum(cir(l),cir(r));
	for(int i=cir(l);i!=cir(r);i=cir(i+1))
		res = min(res,find(cir(l),cir(i))+find(cir(i+1),cir(r)) + s);
	return dp[cir(l)][cir(r)] = res;
}

int main()
{
	int t;
	//cin>>t;
	t = 1;
	while(t--)
	{
		int r;
		cin>>r;
		n = r;
		int i;
		memset(dp,-1,sizeof(dp));
		for(i=0;i<r;i++)
			cin>>a[i];
		pre[0] = 0;
		for(i=0;i<r;i++)
			pre[i+1] = pre[i] + a[i];
		long long ans = INF;
		for(int l=0;l<r;l++)
			ans = min(ans,find(cir(l),cir(l+n-1)));
		cout<<ans<<'\n';
	}
}
