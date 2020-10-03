#include<bits/stdc++.h>
using namespace std;

int rec(int i, vector<int>& one, vector<int>& zero, int z = 0, int o = 0)
{
	if(i == -1)
		return z==o && z!=0;
	return rec(i-1,one,zero,z+zero[i],o+one[i]) + rec(i-1,one,zero,z,o);
}

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	int bit = 0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		int x = v[i];
		for(int j=0;j<20;j++)
		{
			if((x>>j)&1)
				bit = max(bit,j);
		}
	}
	bit++;
	
	vector<int> one(n), zero(n);
	for(int i=0;i<n;i++)
	{
		int x = v[i];
		int c = 0;
		for(int j=0;j<20;j++)
		{
			if((x>>j)&1)
				c++;
		}
		one[i] = c;
		zero[i] = bit - c;
	}
	int res = rec(n-1,one,zero);
	string result;
	for(int i=0;i<bit;i++)
	{
		if((res>>i)&1)
			result.push_back('1');
		else
			result.push_back('0');
	}
	reverse(result.begin(),result.end());
	cout<<result<<'\n';
}

int main()
{
    int t = 1;
    //scanf("%d",&t);
    
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",i);
        solve();
	}
}
