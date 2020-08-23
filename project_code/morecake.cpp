#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	long long f = 0;
	while(t--)
	{
		long long s,n,k,r,sm;
		cin>>s>>n>>k>>r;
		if(r == 1)
			sm = k*n;
		else
			sm = (k*(pow(r,n)-1))/(r-1);
		if(sm <= s)
		{
			long long extra = s - sm;
			cout<<"POSSIBLE "<<extra<<endl;
			f += extra;
		}
		else
		{
			long long required = sm - s;
			cout<<"IMPOSSIBLE "<<required<<endl;
			f -= required;
		}
	}
	puts(f>=0?"POSSIBLE":"IMPOSSIBLE");
}
