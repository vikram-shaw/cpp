#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k, F;
	vector<int> mp(101), map;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>F;
		mp[F]++;
	}
	int res = 0x3f3f3f3f;
	for(int m=1;m<=100;m++)
	{
		map = mp;
		for(int i=1;i<=100;i++)
			map[i] -= m - 1;

		int tem = 0;
		for(int j=1;j<=100;j++)
		{
			if(map[j] > 1)
				tem += map[j];
		}
		res = min(res,tem+k*m);
	}
	cout<<res<<'\n';
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
 
