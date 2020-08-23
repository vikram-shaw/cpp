#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string s,f = "JGEC";
		int l;
		cin>>l>>s;
		int count = 0;
		for(int i=0;i<=l-4;i++)
		{
			if(f == s.substr(i,4))
				count++;
		}
		cout<<count<<'\n';
	}
}
