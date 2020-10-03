#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, p, c, count = 0;
	cin>>n>>p;
	for(int i=1;i<n;i++)
	{
		cin>>c;
		if(c > p)
			count++;
		p = max(p,c);
	}
	cout<<count<<'\n';
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		printf("Case #%d: ",i);
        solve();
	}
}
