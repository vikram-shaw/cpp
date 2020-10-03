#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	s = "." + s;
	int q;
	cin>>q;
	while(q--)
	{
		int t;
		cin>>t;
		int c = 0;
		bool printed = false;
		while(s[t] == ')')
			t++;
		for(int i=t;i<(int)s.length();i++)
		{
			if(s[i] == '(')
				c++;
			else
				c--;
			if(c == 0)
			{
				cout<<i<<'\n';
				printed = true;
				break;
			}
		}
		if(!printed)
			puts("-1");
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
