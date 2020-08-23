#include<bits/stdc++.h>
using namespace std;

int denomination[501];
map<pair<int,int>,int> dp;

int rec(int balance, int n)
{
	if(n < 0)
		return balance == 0;
	int l = 0, r = 0;
	if(dp.count({balance,n}))
		return dp[{balance,n}];
	if(denomination[n] <= balance)
		l = rec(balance-denomination[n],n);
	r = rec(balance,n-1);
	return dp[{balance,n}] = l + r;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, balance;
		dp.clear();
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>denomination[i];
		cin>>balance;
		cout<<rec(balance,n-1)<<'\n';
	}
}
