#include<bits/stdc++.h>
using namespace std;

long long dp[100005];

long long func(int n)
{
	if(n <= 2)
		return 0LL;
	if(n == 3)
		return 1LL;
	if(dp[n] != -1)
		return 0LL;
	long long c = 0LL;
	int m = n;
	while(m != 1)
	{
		int x = m >> 1;
		if(m&1 && x&1)
			c++;
		else
			break;
		m = x;
	}
	return dp[n] = c + func(n-1);
}

int main()
{
	memset(dp,-1,sizeof(dp));
	func(100000);
	dp[1] =  dp[2] = 0;
	dp[3] = 1;
	int q;
	cin>>q;
	while(q--)
	{
		int nn;
		cin>>nn;
		cout<<dp[nn]<<endl;
	}
}
