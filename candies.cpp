#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k;
		cin>>n>>k;
		long long gift;
		long long extra1 = k/2;
		gift = (n/k)*k;
		long long rem = n%k;
		gift+=min(rem,extra1);
		cout<<gift<<'\n';
	}
}
