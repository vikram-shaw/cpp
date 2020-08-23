#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		 long long n,m,k;
		 cin>>n>>m>>k;
		 double nn = n, mm = m, kk = k;
		 long long x = k / (n+m);
		 long long r = k % (n+m);
		 cout<<min(x*n+r,(long long)(ceil(kk/(nn+mm))*nn))<<'\n';
	}
}
