#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	int result = -1;
	int old = INT_MAX;
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		if(k%p == 0)
		{
			if(old > k/p)
			{
				old = k/p;
				result = p;
			}
		}
	}
	cout<<result<<'\n';
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",i);
        solve();
	}
}
