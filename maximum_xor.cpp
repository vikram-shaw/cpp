#include<bits/stdc++.h>
using namespace std;

vector<bool> bitify(long long n)
{
	vector<bool> position(64);
	for(int i=0;i<63;i++)
		if(((n>>i)&1LL) == 1)
			position[i] = true;
	return position;
}

int main()
{
	long long l,r;
	cin>>l>>r;
	vector<bool> ll = bitify(l);
	vector<bool> rr = bitify(r);
	long long result = 0;
	int i;
	for(i=62;i>=0;i--)
	{
		if(ll[i] == rr[i])
			result |= (1LL<<i)&(ll[i]);
		else
			break;
	}
	for(;i>=0;i--)
		result |= (1LL<<i);
	cout<<result<<'\n';
}
