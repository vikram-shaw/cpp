#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int c0=0,c1=0;
	for(char c: s)
		if(c=='0')
			c0++;
		else
			c1++;
	if(!c0 || !c1)
		cout<<s;
	else
		for(int i=0;i<s.length();i++)
			cout<<"10";
	puts("");
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",t);
        solve();
	}
}
