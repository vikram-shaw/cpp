/*
	Euler totient function
	if p is prime Ø(p) = p - 1
	if a = p^n is a prime power then Ø(p^n) = p^n - p^(n-1)
	if gcd(m,n) = 1 then Ø(m*n) = Ø(m)*Ø(n)
	
	Also this can be calculated using 
	Ø(n) = n*(1-1/p1)*(1-1/p2)*.....*(1-1/pk)
*/
#include<bits/stdc++.h>
using namespace std;

int phi(int n)
{
	float res = n;
	if(n%2==0)
	{
		res/=2.0;
		while(n%2==0)
			n/=2;
	}
	for(int i=3;i<=sqrt(n);i+=2)
	{
		if(n%i==0)
		{
			res*=(1.0-1.0/i);
			while(n%i==0)
				n/=i;
		}
	}
	if(n>1)
		res*=(1.0-1.0/n);
	return int(res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<phi(n)<<'\n';
	}
}
