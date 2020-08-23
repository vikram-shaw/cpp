#include<bits/stdc++.h>
using namespace std;
long long xxor(long long n)
{
	if(n%4==0)
		return n;
	if(n%4==1)
		return 1;
	if(n%4==2)
		return n+1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long l,r;
		cin>>l>>r;
		cout<<(xxor(r) ^ xxor(l-1))<<'\n';
	}
}
