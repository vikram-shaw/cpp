#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long x,y;
	cin>>x>>y;
	long sm = x + y;
	long f = 0;
	for(int i=0;i<31;i++)
	{
		if(f == sm)
		{
			puts("IMPOSSIBLE");
			return;
		}
		f += 1LL<<i;
	}
	
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		printf("Case #%d: ",t);
        solve();
	}
}
