#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m;
	cin>>n>>m;
	map<int,int> mp1, mp2;
	set<int> st;
	for(int i=0;i<n;i++)
	{
		int r;
		cin>>r;
		mp1[r]++;
		st.insert(r);
	}
	bool found = false;
	for(int i=0;i<m;i++)
	{
		int r;
		cin>>r;
		mp2[r]++;
		if(st.count(r))
			found = true;
	}
	if(!found)
	{
		puts("NO");
		return;
	}
	int small, tem;
	small = tem = INT_MAX;
	for(pair<int,int> p: mp1)
	{
		if(p.second%2 && mp2[p.first]%2)
		{
			int mn = min(p.second,mp2[p.first]);
			if(tem > mn)
			{
				tem = mn;
				small = p.first;
			}
		}
	}
	for(pair<int,int> p: mp2)
	{
		if(p.second%2 && mp1[p.first]%2)
		{
			int mn = min(p.second,mp1[p.first]);
			if(tem > mn)
			{
				tem = mn;
				small = p.first;
			}
		}
	}
	puts("YES");
	cout<<tem<<' '<<small<<'\n';
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
