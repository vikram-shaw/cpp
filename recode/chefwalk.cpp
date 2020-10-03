#include<bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9+7;

void solve()
{
	//formula = n*(n-1) + n + p*2*n + q*(q+1)
	long long n,k;
	cin>>n>>k;
	if(n==0)
	{
		long long p = k-1;
		cout<<((p*(p+1))%MOD + n%MOD)%MOD<<endl;
		return;
	}
	long long p = k/2;
	long long q = ceil(double(k)/2)-1;
	long long res1 = ((n%MOD)*((n-1)%MOD))%MOD;
	res1 += (n%MOD);
	res1 %= MOD;
	long long res2 = (((2*n%MOD)%MOD)*(p%MOD))%MOD;
	long long res3 = (q%MOD*((q+1)%MOD))%MOD;
	long long res = ((res1%MOD) + (res2%MOD))%MOD;
	res = ((res%MOD) + (res3%MOD))%MOD;
	cout<<res<<endl;
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
