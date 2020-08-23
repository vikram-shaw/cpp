#include<bits/stdc++.h>
using namespace std;

long long GInv(long long n)
{
	long long r = 0, m = 0;
	for(int i=0; n; i++)
	{
		r += ceil(n/2.0)*(1<<i);//adding all bits from 0 to 32 at a time
		n/=2;
		m++;//total number of -1
	}
	return r+m;
}

long long G(long long n)
{
	return n*(n+1)/2 - GInv(n);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long l,r;
		cin>>l>>r;
		cout<<G(r)-G(l-1)<<'\n';//G(L,R) = G(R) - G(L)
	}
}
