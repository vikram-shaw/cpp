#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> v(n);
	for(int& x: v)
		scanf("%d",&x);
	int res = 0;
	while(q--)
	{
		char query;
		int l,r;
		cin>>query>>l>>r;
		if(query=='U')
		{
			v[l-1] = r;
		}
		else
		{
			int k=1;
			int p = 1;
			for(int i=l-1;i<r;i++)
			{
				res += v[i]*p*(k++);
				if(p==1)
					p = -1;
				else
					p = 1;
			}
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
