#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	for(int& x: v)
		scanf("%d",&x);
	int r = v[0];
	int ans = v[0];
	for(int i=1;i<n;i++)
	{
		r = lcm(r,v[i]);
		ans = min(ans,v[i]);
	}
	int res = r;
	int g = r;
	for(int i=m;i>=1;i--)
	{
		int g1 = lcm(r,i);
		if(g1 >= g)
		{
			g = g1;
			r = i;
		}
	}
	cout<<r<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        solve();
}
