#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long n;
	cin>>n;
	map<long,long> map;
	for(long i=0;i<n;i++)
	{
		long r;
		cin>>r;
		map[r]++;
	}
	
	for(long i=0;i<n;i++)
	{
		long r;
		cin>>r;
		map[r]--;
	}
	vector<long> fst, snd;
	long mn = (long)0x3f3f3f3f3f;
	
	for(pair<long,long> p: map)
	{
		mn = min(mn,p.first);
		long second = abs(p.second);
		if(second%2)
		{
			puts("-1");
			return;
		}
		if(second != 0)
		{
			if(p.second > 0)
			for(long i=0;i<(second>>1);i++)
				fst.push_back(p.first);
			else
			for(long i=0;i<(second>>1);i++)
				snd.push_back(p.first);
		}
	}
	reverse(snd.begin(),snd.end());
	long result = 0;
	for(long i=0;i<(long)fst.size();i++)
		result += min(mn<<1,min(fst[i],snd[i]));
	cout<<result<<'\n';
}

int32_t main()
{
    long t;
    scanf("%ld",&t);
    for(long i=1;i<=t;i++)
    {
		//prlongf("Case #%d: ",i);
        solve();
	}
}
