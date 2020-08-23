#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string res="";
	int n;
	scanf("%d",&n);
	string s[n];
	int mx = 0;
	for(int i=0;i<n;i++)
		cin>>s[i];
	vector<int> v(n);
	for(int i=0;i<n;i++)
		v[i] = s[i].length()-1;
	bool correct;
	while(true)
	{
		correct = true;
		for(int i=0;i<n-1;i++)
		{
			if(v[i]==-1 || s[i][v[i]]=='*')
				continue;
			if(s[i][v[i]]!=s[i+1][v[i+1]])
			{
				correct = false;
				break;
			}
			v[i]--;
		}
		if(!correct)
			res = s[i+1][v[i+1]] + res;
		else
			break;
	}
	if(!correct)
		puts("*");
	else
		cout<<res<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		printf("Case #%d: ",t);
        solve();
	}
}
