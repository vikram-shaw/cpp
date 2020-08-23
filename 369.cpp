#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9+7;
int dp[51][2][51][51][51];

int solve(string& s, int i, int tight, int three = 0, int six = 0, int nine = 0)
{
	if(i == (int)s.size())
		return three != 0 && three == six && six == nine;
	if(dp[i][tight][three][six][nine] != -1)
		return dp[i][tight][three][six][nine];
	int ed = tight ? s[i] - '0':9;
	int res = 0;
	for(int j=0;j<=ed;j++)
	{
		if(j == 3)
		{
			res = (res + solve(s,i+1,tight && (j == ed),three+1,six,nine))%MOD;
		}
		else if(j == 6)
		{
			res = (res + solve(s,i+1,tight && (j == ed),three,six+1,nine))%MOD;
		}
		else if(j == 9)
		{
			res = (res + solve(s,i+1,tight && (j == ed),three,six,nine+1))%MOD;
		}
		else
		{
			res = (res + solve(s,i+1,tight && (j == ed),three,six,nine))%MOD;
		}
	}
	return dp[i][tight][three][six][nine] = res;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		memset(dp,-1,sizeof(dp));
		cin>>a>>b;
		int res = solve(b,0,1);
		memset(dp,-1,sizeof(dp));
		res -= solve(a,0,1);
		cout<<res<<'\n';
	}
}
