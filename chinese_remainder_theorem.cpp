#include<bits/stdc++.h>
using namespace std;

long long inv(long long x, long long n, long long m) 
{
	if(n == 0)
		return 1LL;
	if(n&1)
		return (inv(x,n-1,m) % m * x) % m;
	long long c = inv(x,n/2,m) % m;
	return (c * c) % m;
}

int main()
{
	long long n, M = 1;
	cin>>n;
	vector<long long> a(n), r(n), m(n), x(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
		M *= r[i];
	}
	for(int i=0;i<n;i++)
	{
		m[i] = M/r[i];
		x[i] = inv(m[i],r[i]-2,r[i]);
	}
	long long answer = 0;
	for(int i=0;i<n;i++)
	{
		answer += ((m[i] % M) * (a[i] % M) * (x[i] % M)) % M;
		answer %= M;
	}
	for(int i=0;i<n;i++)
	{
		cout<<answer<<" % "<<r[i]<<" = "<<a[i]<<"\n";
	}
}
