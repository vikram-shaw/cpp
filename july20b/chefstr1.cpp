#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,p,c;
	long long res = 0LL;
	cin>>n>>p;
	for(int i=1;i<n;i++)
	{
		cin>>c;
		res += abs(p-c)-1;
		p = c;
	}
	cout<<res<<'\n';
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
