#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	set<int> s;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		s.insert(v[i]);
	}
	sort(v.begin(),v.end());
	int q;
	cin>>q;
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		int c = l + r;
		if(s.count(c))
		{
			puts("-1");
			continue;
		}
		cout<<(lower_bound(v.begin(),v.end(),c)-v.begin())<<'\n';
	}
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
