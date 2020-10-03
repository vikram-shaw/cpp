#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,c=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long num = i;
		vector<long long> v;
		while(num!=0)
		{
			long long r = num%10;
			bool brk = false;
			for(long long j=0;j<v.size();j++)
			{
				if(v[j]<r)
				{
					brk = true;
					break;
				}
			}
			if(brk){
				c++;
				break;
			}
			v.push_back(r);
			num/=10;
		}
	}
	cout<<n-c<<'\n';
}
