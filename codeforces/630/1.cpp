#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long a,b,c,d;
		scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
		a -= b;
		c -= d;
		long x,y,x1,y1,x2,y2;
		scanf("%ld%ld%ld%ld%ld%ld",&x,&y,&x1,&y1,&x2,&y2);
		x -= a;
		y -= c;
		if(x1 <= x && x <= x2 && y1 <= y && y <= y2)
			puts("Yes");
		else
			puts("No");
	}
}
