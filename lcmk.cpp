#include<bits/stdc++.h>
using namespace std;

const long long MAX = 1000005;
long long prime[MAX+1];
map<long long,long long> max_map;

void sieve()
{
	prime[0] = prime[1] = 1;
	for(long long i=2;i<MAX;i++)
	{
		if(prime[i] == 0)
		{
			for(long long j=i*i;j<MAX;j+=i)
			{
				if(prime[j] == 0)
				{
					prime[j] = i;
				}
			}
			prime[i] = i;
		}
	}
}

long long power(long long a, long long n, long long m)
{
	if(n == 0)
		return 1;
	if(n&1)
		return (a*power(a,n-1,m))%m;
	long long t = power(a,n>>1,m);
	return ((t%m)*(t%m))%m;
}

long long lcm(vector<long long>& v, long long m)
{
	for(long long i=0;i<(long long)v.size();i++)
	{
		long long num = v[i];
		map<long long,long long> temp;
		while(num > 1)
		{
			long long factor = prime[num];
			temp[factor]++;
			num/=factor;
		}
		
		for(pair<long long,long long> p: temp)
			max_map[p.first] = max(max_map[p.first],p.second);
	}
	
	long long ans = 1;
	for(pair<long long,long long> p: max_map)
		ans = (ans*power(p.first,p.second,m))%m;
	return ans;
}
					

int main()
{
	sieve();
	long long t;
	cin>>t;
	while(t--)
	{
		max_map.clear();
		long long n,m,k;
		cin>>n>>m>>k;
		vector<long long> v(n);
		for(long long i=0;i<n;i++)
			cin>>v[i];
		
		cout<<power(lcm(v,m),k,m)<<'\n';
	}
}
