#include<bits/stdc++.h>
using namespace std;

int calculate(int n)
{
	int res = 0;
	int c = 1;
	int t = n;
	while(n>1)
	{
		n>>=1;
		cout<<n<<"*pow(2,"<<c<<")\n";
		res+=n*(1<<c);
		c++;
	}
	return res;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		cin>>l;
		int res = 0;
		cout<<calculate(l)<<'\n';
	}
}
