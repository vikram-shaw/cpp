#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int p = 0, c = 0;
	bool yes = true;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x < p || y < c || y-c > x-p)
			yes = false;
		p = x;
		c = y;
	}
	if(yes)
		puts("YES");
	else
		puts("NO");
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",t);
        solve();
	}
}
