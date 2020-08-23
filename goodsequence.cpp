#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int l = s.length();
	int res = 0,i = 0;
	while(i<l)
	{
		int p = 0, q = 0;
		while(s[i]=='<' && i<l)
		{
			i++;
			p++;
		}
		while(s[i]=='>' && i<l)
		{
			i++;
			q++;
		}
		if(p<q)
			swap(p,q);
		p = p*(p+1)/2;
		q = q*(q-1)/2;
		res+= p + q;
	}
	cout<<res<<'\n';
}
