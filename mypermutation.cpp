#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int cnt = 0;
vector<string> res;
void permute(string r,int p = 0)
{
	if(p==r.length()){
		//cout<<r<<'\n';
		res.push_back(r);
		cnt++;
		return;
	}
	for(pair<char,int> it: mp)
	{
		if(it.second!=0)
		{
			mp[it.first]--;
			r[p]=it.first;
			permute(r,p+1);
			mp[it.first]++;
		}
	}
}

int main()
{
	string s;
	cin>>s;
	for(char c: s)
		mp[c]++;
	for(int i=0;i<s.length();i++)
		permute(s.substr(i));
	cout<<cnt<<'\n';
	for(string ss: res)
		cout<<ss<<'\n';
}
