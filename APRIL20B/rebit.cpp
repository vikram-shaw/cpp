#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353

long long power(long long x,long long n)
{
	if(n==0)
		return 1;
	if(n%2==0)
	{
		long long y=power(x,n/2);
		return (y*y)%MOD;
	}
	return ((x%MOD)*(power(x,n-1)))%MOD;
}

void solve()
{
	cout<<(power(16,MOD-2))%MOD<<endl;
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
