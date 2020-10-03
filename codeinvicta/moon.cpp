#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		int s = n*x + m*y;
		if(s%2==1)
		{
			puts("NO");
			continue;
		}
		if(x==0)
		{
			if(m%2==0)
				puts("YES");
			else
				puts("NO");
			continue;
		}
		if(y==0)
		{
			if(n%2==0)
				puts("YES");
			else
				puts("NO");
			continue;
		}
		s/=2;
		bool found = false;
		for(int p2=0;p2<=m;p2++)
		{
			int g = s-p2*y;
			if(g<0)
				break;
			if(g%x==0)
			{
				int p1 = g/x;
				if(p1 <= n)
				{
					found = true;
					break;
				}
			}
		}
		puts(found?"YES":"NO");
	}
}
