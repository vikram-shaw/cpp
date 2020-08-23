#include<bits/stdc++.h>
using namespace std;

long long bitcount[32];

void bitify()
{
	long long x;
	cin>>x;
	for(int i=0;i<32;i++)
	{
		if((x>>i)&1)
			bitcount[i]++;
	}
}

map<tuple<int,int,long>,long long> dp;

long long rec(vector<long long>& v,int c, int l, long long value)
{
	if(c < 0)
		return value == 0 && l == 0;
	if(l < 0)
		return 0;
	if(dp.count(make_tuple(c,l,value)))
		return dp[make_tuple(c,l,value)];
	long long r1 = 0LL, r2 = 0LL;
	if(v[c] <= value)
		r1 = rec(v, c - 1, l - 1, value - v[c]);
	if(c >= l)
		r2 = rec(v,c - 1, l, value);
	return dp[make_tuple(c,l,value)] = r1 + r2;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(bitcount,0,sizeof(bitcount));
		long long n,l;
		cin>>n>>l;
		for(int i=0;i<n;i++)
			bitify();
		
		vector<long long> v(32);
		
		for(int i=0;i<32;i++)
			v[i] = (1LL<<i)*bitcount[i];
		
		int count = 0;
		
		for(int i=31;i>=0;i--)
		{
			if(bitcount[i])
				count++;
		}
		if(count < l)
		{
			puts("-1");
			continue;
		}
		sort(v.begin(),v.end(),greater<long long>());
		long long value = 0LL;
		for(int i=0;i<l;i++)
			value +=v[i];
		int c=0;
		for(c=0;c<32;c++)
			if(v[c] == 0)
				break;
		cout<<rec(v,c-1,l,value)<<'\n';
		dp.clear();
	}
}
