#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	scanf("%d",&n);
	int p = 0, r;
	bool flag = true;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&r);
		if(r == 0)
			p--;
		else
		{
			if(flag && p > 1)
			{
				puts("NO");
				flag = false;
			}
			p = 6;
		}
	}
	if(flag)
		puts("YES");
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve();
}
