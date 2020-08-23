#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k,res;
		cin>>n>>k;
		long long rem = k % (2*(n-1));
		if(rem > n)
			res = 2*n - rem;
		else if(rem == 0)
			res = 2;
		else
			res = rem;
		cout<<res<<'\n';
	}
}
