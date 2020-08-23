#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, c = 0;
	char pre = 'U';
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i] == pre)
			c++;
		else
			pre = s[i];
	}
	cout<<c<<'\n';
}
