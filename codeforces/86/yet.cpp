#include<bits/stdc++.h>
using namespace std;

long long prefix[400005];
long long a,b,q,lim;

void build(long long lim)
{
	::lim = lim;
	prefix[0] = 0;
	for(long long x=1;x<=lim;x++)
	{
		prefix[x] = prefix[x-1];
		if(x%a%b != x%b%a)
			prefix[x]++;
	}
}

long long result(long long l)
{
	long long qu = l / (lim);
	long long re = l % (lim);
	return prefix[lim-1]*qu + prefix[re];
}

long long result(long long l,long long r)
{
	return result(r) - result(l-1);
}

void solve()
{
	cin>>a>>b>>q;
	build(a*b);
	while(q--)
	{
		long long l,r;
		cin>>l>>r;
		cout<<result(l,r)<<' ';
	}
	puts("");
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
