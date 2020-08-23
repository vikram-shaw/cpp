#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9+7;

int L[8005],D[8005];


int rec(int n, int k)
{
	if(k == 0)
		return 1;
	if(n < 0)
		return 0;
	int l = 0, r = 0;
	if(L[n] <= k && D[n])
	{
		D[n]--;
		l = rec(n,k-D[n]);
		D[n]++;
	}
	r = rec(n-1,k);
	return (l % MOD + r % MOD) % MOD;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>k>>n;
		for(int i=0;i<n;i++)
			cin>>L[i];
		for(int i=0;i<n;i++)
			cin>>D[i];
		cout<<rec(n-1,k)<<'\n';
	}
}
