#include<bits/stdc++.h>
using namespace std;

long long dp[65][2][2][2][2];

long long pattern110(string& n, int i, int pp, int p, bool tight, bool found)
{
	if(i == -1)
		return found;
	
	if(pp != -1 &&dp[i][pp][p][tight][found] != -1)
		return dp[i][pp][p][tight][found];
	if(tight)
	{
		long long res = pattern110(n,i-1,p,0,n[i] == '0',found || (pp==1&&p==1));
		if(n[i] == '1')
			res += pattern110(n,i-1,p,1,tight,found);
		if(pp != -1)
			dp[i][pp][p][tight][found] = res;
		return res;
	}
	
	long long res = pattern110(n,i-1,p,0,false,found||(pp==1&&p==1)) + pattern110(n,i-1,p,1,false,found);
	if(pp != -1)
		dp[i][pp][p][tight][found] = res;
	return res;
}

string convert(long long n)
{
	string res = "";
	for(int i=61;i>=0;i--)
	{
		if((n>>i)&1)
			res.push_back('1');
		else
			res.push_back('0');
	}
	reverse(res.begin(),res.end());
	return  res;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long l,r;
		cin>>l>>r;
		string ll = convert(l-1);
		string rr = convert(r);
		
		memset(dp,-1,sizeof(dp));
		long long right = pattern110(rr,61,-1,-1,true,false);
		memset(dp,-1,sizeof(dp));
		long long left = pattern110(ll,61,-1,-1,true,false);
		
		cout<<right-left<<'\n';
	}
}
