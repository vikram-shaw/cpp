#include<bits/stdc++.h>
using namespace std;
string s;
map<pair<int,char>,int> dp;

int rec(int n, char pre)
{
	if(n < 0)
		return 1;
	if(dp.count({n,pre}))
		return dp[{n,pre}];
	if(s[n] == pre)
	{
		if(pre == 'f')
			return dp[{n,pre}] = rec(n-1,'k') + rec(n-1,s[n]);
		else if(pre == 'g')
			return dp[{n,pre}] = rec(n-1,'c') + rec(n-1,s[n]);
	}
	return dp[{n,pre}] = rec(n-1,s[n]);
}

int main()
{
	cin>>s;
	int l = s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i] == 'c' || s[i] == 'k')
		{
			puts("0");
			return 0;
		}
	}
	cout<<rec(l-1,'c')<<'\n';
}
