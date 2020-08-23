#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000010;
const int MOD = (int)1e9+9;
long long dp[MAX];

void cal()
{
	dp[0] = dp[1] = 0;
	dp[2] = dp[3] = 1;
	for(int i=4;i<MAX;i++)
		dp[i] = (dp[i-2] % MOD + dp[i-3] % MOD) % MOD;
}
	
int main()
{
	int t;
	cin>>t;
	cal();
	while(t--)
	{
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
}
