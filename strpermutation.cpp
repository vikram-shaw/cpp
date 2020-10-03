#include<bits/stdc++.h>
using namespace std;

void permutation(string& s,string res = "")
{
	if(s.length()==1)
	{
		res += s[0];
		cout<<res<<'\t';
		return;
	}
	for(int i=0;i<s.length();i++)
	{
		string s1 = s.substr(0,i)+s.substr(i+1);
		permutation(s1,res+s[i]);
	}
}

int main()
{
	string s;
	cin>>s;
	permutation(s);
}
