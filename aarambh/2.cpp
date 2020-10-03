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
		long long p,m,n;
		cin>>p>>m>>n;
		long long over = n/m;
		long long remball = n%m;
		long long f , l;
		if(p<=n)
		{
			over = p/m;
			remball = p%m;
			if(over == 0)
			{
				f = 1;
				cout<<p-1<<'\n';
				continue;
			}
			else
			{
				f = 2 + (over-1)*m;
				l = f + m;
			}
			cout<<l+remball<<'\n';
			continue;
		}
		if(over == 0)
		{
			f = 1;
			l = 2;
		}
		else
		{
			f = 2 + (over-1)*m;
			l = f + m;
		}
		cout<<l+remball<<'\n';
	}
}
