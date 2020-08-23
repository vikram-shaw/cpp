#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(),v.end());
		int p = binary_search(v.begin(),v.end(),m-1);
		if(p)
		{
			int c = 0;
			int tem = m;
			p = lower_bound(v.begin(),v.end(),m-1)-v.begin();
			for(int i=p;i>=0;i--)
			{
				if(v[i] == m-1)
					c++;
				else
					break;
				m--;
			}
			if(binary_search(v.begin(),v.end(),tem))
				c--;
			cout<<c+(n-p-1)<<endl;
		}
		else
			puts("-1");
	}
}
//1 2 3 3 4 42 53 64 89 432
