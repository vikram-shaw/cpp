#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,k;
	cin>>n>>k;
	vector<long> v(n),res(n);
	long pre = 0;
	for(long i=0;i<n;i++)
	{
		cin>>v[i];
		pre += v[i];
	}
	long u = k / n;
	for(long i=0;i<n;i++)
	{
		long l = i, val = 0, r = (i + k) % n;
		while(l!=r)
		{
			val += v[l];
			l++;
			l %= n;
		}
		res[(r-1+n)%n] = val;
	}
	if(u!=0)
	{
		for(long i=0;i<n;i++)
			res[i] += u*pre;
	}
	for(long i=0;i<n;i++)
		cout<<res[i]<<" ";
	cout<<"\n";
}
