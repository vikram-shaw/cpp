#include<bits/stdc++.h>
using namespace std;

void solve()
{
	set<long long> mul2,mul4;
	long long n;
	scanf("%lld",&n);
	vector<long long> v(n);
	long long i=0;
	for(long long& x: v)
	{
		scanf("%lld",&x);
		if(x%2==0)
		{
			mul2.insert(i);
			if(x%4==0)
				mul4.insert(i);
		}
		i++;
	}
	long long count = 0;
	for(i=0;i<n;i++)
	{
		if(v[i]%2==0)
		{
			if(v[i]%4==0)
			{
				count += (n-i);
				mul4.erase(mul4.begin());
				mul2.erase(mul2.begin());
			}
			else
			{
				mul2.erase(mul2.begin());
				if(mul2.size()==0)
					continue;
				count += (n-*mul2.begin());
			}
		}
		else
		{
			if(mul2.size()==0)
			{
				count += (n-i);
				continue;
			}
			if(mul4.size()!=0)
			{
				long long m4 = *mul4.begin();
				long long m2f = *mul2.begin();
				if(m4<=m2f)
				{
					count += (n-i);
					continue;
				}
				if(mul2.size()>=2)
				{
					long long m2s = *(++mul2.begin());
					long long mn = min(m2s,m4);
					count += (m2f - i) + (n - mn);
					continue;
				}
				count += (m2f - i);
				continue;
			}
			long long m2f = *mul2.begin();
			if(mul2.size()>=2)
			{
				long long m2s = *(++mul2.begin());
				count += (m2f - i) + (n - m2s);
				continue;
			}
			count += (m2f - i);
		}
	}
	printf("%lld\n",count);
}

int main()
{
    int t;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve();
}
