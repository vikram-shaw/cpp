#include<bits/stdc++.h>
using namespace std;

bool check(int n)
{
	int c = 0;
	for(int i=0;i<31;i++)
		c+=(1<<i)&n?1:0;
	return c%2;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		int even = 0,odd = 0;
		for(int i=0;i<n;i++)
		{
			int r;
			scanf("%d",&r);
			check(r)?odd++:even++;
		}
		while(q--)
		{
			int p;
			scanf("%d",&p);
			if(check(p))
				printf("%d %d\n",odd,even);
			else
				printf("%d %d\n",even,odd);
		}
	}
}
