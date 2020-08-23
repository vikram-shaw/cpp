#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int r = n+m;
	if(n <= 9 && m<=9)
		printf("%d\n",r);
	else if(n <= 9)
	{
		int d1 = n;
		int d2 = m/10;
		int d3 = m%10;
		swap(d1,d2);
		n = d1;
		m = d2*10 + d3;
		r = max(r,n+m);
		swap(d1,d2);
		swap(d1,d3);
		r = max(r,n+m);
		printf("%d\n",r);
	}
	else if(m <= 9)
	{
		int d1 = m;
		int d2 = n/10;
		int d3 = n%10;
		swap(d1,d2);
		n = d1;
		m = d2*10 + d3;
		r = max(r,n+m);
		swap(d1,d2);
		swap(d1,d3);
		r = max(r,n+m);
		printf("%d\n",r);	
	}
	else
	{
		int d1 = n/10;
		int d2 = n%10;
		int d3 = m/10;
		int d4 = m%10;
		swap(d1,d3);
		n = d1*10 + d2;
		m = d3*10 + d4;
		r = max(r,m+n);
		swap(d1,d3);
		swap(d1,d4);
		n = d1*10 + d2;
		m = d3*10 + d4;
		r = max(r,n+m);
		swap(d1,d4);
		swap(d2,d3);
		n = d1*10 + d2;
		m = d3*10 + d4;
		r = max(r,n+m);
		swap(d2,d3);
		swap(d2,d4);
		n = d1*10 + d2;
		m = d3*10 + d4;
		r = max(r,n+m);
		printf("%d\n",r);
	}
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        solve();
}
