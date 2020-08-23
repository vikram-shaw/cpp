#include<bits/stdc++.h>
using namespace std;

string res="";

int rec(string s, int n, int i=0)
{
	if(n==i)
	{
		cout<<res<<endl;
		return 1;
	}
	int g = 0;
	if(n-i > 1 && s[i] != '0' && s[i] <='2' && s[i+1]<='6')
	{
		int r = (s[i]-'0')*10+(s[i+1]-'0');
		res += char('A' + r - 1);
		g = rec(s,n,i+2);
		res.pop_back();
	}
	int h = 0;
	if(s[i] !='0')
	{
		int r = (s[i]-'0');
		res += char('A' + r - 1);
		h = rec(s,n,i+1);
		res.pop_back();
	}
	return g+h;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<rec(s,s.length())<<endl;
	}
}
