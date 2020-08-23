#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long long n;
	cin>>n;
	map<long long,long long> x,y;
	long long len = (n<<2)-1;
	for(long long i=0;i<len;i++)
	{
		long long u,v;
		cin>>u>>v;
		x[u]++;
		y[v]++;
	}
	long long xr, yr;
	for(pair<long long,long long> p: x)
	{
		if(p.second%2)
		{
			xr = p.first;
			break;
		}
	}
	for(pair<long long,long long> p: y)
	{
		if(p.second%2)
		{
			yr = p.first;
			break;
		}
	}
	cout<<xr<<' '<<yr<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--)
		solve();
}
