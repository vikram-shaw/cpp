#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int mx = -1;
	int num = -1;
	for(int i=0;i<n;i++)
	{
		int y = v[i];
		int c =  0;
		int p = i-2;
		for(int j=i;j<n;j++)
		{
			if(y == v[j])
			{
				if(p + 1 == j)
					continue;
				p = j;
				c++;
			}
		}
		if(mx < c)
		{
			mx = c;
			num = y;
		}
		else if(mx == c && num > y)
		{
			num = y;
		}
	}
	
	cout<<mx<<' '<<num<<endl;
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
