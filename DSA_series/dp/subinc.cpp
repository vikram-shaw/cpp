#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n, pre, curr, res = 0L, nn = 1L;
		cin>>n>>pre;
		for(int i=1;i<n;i++)
		{
			cin>>curr;
			if(curr >= pre)
				nn++;
			else
			{
				res += nn * (nn + 1) / 2;
				nn = 1L;
			}
			pre = curr;
		}
		res += nn * (nn + 1) / 2;
		cout<<res<<'\n';
	}
}
