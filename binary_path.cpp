#include<bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int nn;
		cin>>nn;
		int c = 0;
		for(int n = nn;n>=1;n--)
		{
			int cc = 0;
			int m = n;
			while(m != 1)
			{
				int x = m >> 1;
				if(m&1 && x&1)
					cc++;
				else
					break;
				m = x;
			}
			c += cc;
		}
		cout<<c<<'\n';
	}
}
