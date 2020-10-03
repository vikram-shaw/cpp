#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
int isprime[MAX];

void solve()
{
	int n;
	cin>>n;
	cout<<max(1,n/2)<<endl;//minimum number of days
	if(n==1)
	{
		puts("1 1");
		return;
	}
	if(n==2)
	{
		puts("2 1 2");
		return;
	}
	if(n==3)
	{
		puts("3 1 2 3");
		return;
	}
	puts("3 1 2 3");
	for(int i=1;i<n-3;i+=2)
		printf("2 %d %d\n",i+3,i+4);
	if(!(n&1))
		printf("1 %d\n",n);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    long long t;
    cin>>t;
    for(long long i=1;i<=t;i++)
        solve();
}
