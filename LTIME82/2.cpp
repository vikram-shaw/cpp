#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	map<char,int> mp;
	int k,x;
	scanf("%d%d",&k,&x);
	int count = 0;
	for(char c: s)
	{
		mp[c]++;
		if(mp[c] > x)
		{
			if(k==0)
				break;
			k--;
			count--;
		}
		count++;
	}
	printf("%d\n",count);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        solve();
}
