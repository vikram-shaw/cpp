#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s, p;
	cin>>s>>p;
	map<char,int> mp;
	for(char c: s)
		mp[c]++;
	for(char c: p)
		mp[c]--;
	string res1 = "",res2 = "";
	char i;
	for(i='a';i<p[0];i++)
	{
		for(int j=0;j<mp[i];j++)
			res1.push_back(i);
		mp.erase(i);
	}
	res2 = res1;
	pair<char,int> tem = {i,mp[i]};
	for(int j=0;j<tem.second;j++)
		res2.push_back(tem.first);
	res1 += p;
	res2 += p;
	for(pair<char,int> p: mp)
	{
		for(int i=0;i<p.second;i++)
		{
			res1.push_back(p.first);
			if(p.first == tem.first)
				continue;
			res2.push_back(p.first);
		}
	}
	cout<<min(res1,res2)<<'\n';
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
