#include<bits/stdc++.h>
using namespace std;

bool isperfect(int n)
{
	int sq = sqrt(n);
	return sq*sq == n;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> pre(n+1);
	int x;
	pre[0] = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		pre[i] = x + pre[i-1];
	}
	int res = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(isperfect(pre[j]-pre[i]))
				res++;
		}
	}
	cout<<res<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		printf("Case #%d: ",i);
        solve();
	}
}
