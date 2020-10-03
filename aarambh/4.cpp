#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long total = n*(n-1)/2;
		map<long long,long long> xx,yy;
		for(int i=0;i<n;i++)
		{
			long long x,y;
			cin>>x>>y;
			xx[x]++;
			yy[y]++;
		}
		for(pair<long long,long long> p : xx)
		{
			total-=(p.second*(p.second-1)/2);
		}
		for(pair<long long,long long> p : yy)
		{
			total-=(p.second*(p.second-1)/2);
		}
		cout<<total<<'\n';
	}
}
