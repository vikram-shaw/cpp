#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int& x: v)
		scanf("%d",&x);
	int res = 0;
	for(int i=0;i<n;i++)
	{
		if(v[i] == k)
		{
			int kk = k;
			while(i<n && v[i] == kk)
				kk--,i++;
			if(kk==0)
				res++;
			i--;
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
