#include<bits/stdc++.h>
using namespace std;

int power(string s)
{
	int c = 0;
	for(int i=0;i<(int)s.length();i++)
		c += s[i]-'0';
	return c;
}

void solve()
{
	int n, chef = 0, monty = 0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int p1 = power(s1);
		int p2 = power(s2);
		if(p1 == p2)
		{
			chef++;
			monty++;
		}
		else if(p1 > p2)
			chef++;
		else
			monty++;
	}
	if(chef == monty)
		cout<<"2 "<<chef<<'\n';
	else if(chef > monty)
		cout<<"0 "<<chef<<'\n';
	else
		cout<<"1 "<<monty<<'\n';
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
