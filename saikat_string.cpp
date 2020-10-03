#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int l = s.length();
	set<string> st;
	for(int i=0;i<l;i++)
	{
		if(s.substr(i,l-i) <= s)
		{
			for(int j=i;j<l;j++)
				st.insert(s.substr(i,j-i+1));
		}
	}
	cout<<st.size()<<'\n';
} 
