#include<bits/stdc++.h>
using namespace std;

void read(vector<int>& v)
{
	for(int& x: v)
		scanf("%d",&x);
}

int main()
{
	int t,s;
	cin>>t>>s;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> chef(n),frnd(n);
		read(chef);
		read(frnd);
		sort(chef.begin(),chef.end());
		sort(frnd.begin(),frnd.end());
		if(s==1)
		{
			set<int> s;
			for(int x: frnd)
				s.insert(x);
			if(chef[0]>=frnd[0])
			{
				puts("NO");
				continue;
			}
			s.insert(chef[0]);
			int i;
			for(i=1;i<n;i++)
			{
				if(chef[i]>=frnd[i] || s.find(chef[i])==s.end())
					break;
				s.insert(chef[i]);
			}
			if(i==n)
				puts("YES");
			else
				puts("NO");
		}
		else
			puts("YES");
	}
}
