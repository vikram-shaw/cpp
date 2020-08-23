#include<bits/stdc++.h>
using namespace std;

long long bitcount[32];

void bitify()
{
	long long x;
	cin>>x;
	for(int i=0;i<32;i++)
	{
		if((x>>i)&1)
			bitcount[i]++;
	}
}

long long C(int n, int r)
{
    if(r > n - r) r = n - r;
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(bitcount,0,sizeof(bitcount));
		long long n,l;
		cin>>n>>l;
		for(int i=0;i<n;i++)
			bitify();
		
		vector<long long> v(32);
		
		for(int i=0;i<32;i++)
			v[i] = (1LL<<i)*bitcount[i];
		
		int count = 0;
		
		for(int i=31;i>=0;i--)
		{
			if(bitcount[i])
				count++;
		}
		if(count < l)
		{
			puts("-1");
			continue;
		}
		sort(v.begin(),v.end(),greater<long long>());
		n = 0;
		long long r = 0;
		
		for(int i=0;i<l;i++)
			if(v[i] == v[l-1])
				r++;
		
		for(int i=0;i<32;i++)
			if(v[i] == v[l-1])
				n++;
		cout<<C(n,r)<<'\n';
	}
}
