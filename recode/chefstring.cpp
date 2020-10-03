#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int l = s.length();
	if(l<=2)
	{
		puts("YES");
		return;
	}
	string s1 = s.substr(1,l-1) + s[0];
	string s2 = s[l-1] + s.substr(0,l-1);
	puts(s1==s2?"YES":"NO");
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
