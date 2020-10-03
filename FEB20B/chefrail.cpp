#include<bits/stdc++.h>
using namespace std;
void read(vector<long>& x,set<long>& st)
{
	for(long &r: x)
	{
		scanf("%ld",&r);
		st.insert(r);
	}
}

vector<int> dev(int n)
{
	vector<pair<int,int>> pf;
	long long m = 1LL*n*n;
	int c = 0;
	if(m%2)
	{
		while(m%2==0)
		{
			c++;
			m/=2;
		}
		pf.push_back(2,c);
	}
	for(int i=3;i<=sqrt(m);i+=2)
	{
		if(m%i==0)
		{
			c = 0;
			while(n%i==0)
			{
				c++;
				n/=i;
			}
			pf.push_back(i,c);
		}
	}
	
}

long counter(long curr,set<long>& s)
{
	long count = 0;
	int dec = 1;
	for(long i: dev(curr))
	{
		if(s.find(i)!=s.end() && s.find(-search/i)!=s.end())
			count++;
		if(i!=search/i)
			if(s.find(-i)!=s.end() && s.find(search/i)!=s.end())
				count++;
	}
	return count;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n,m;
		cin>>n>>m;
		set<long> xx,yy;
		vector<long> x(n),y(m);
		read(x,xx);
		read(y,yy);
		long count = 0;
		for(long curr: x)
			count+=counter(abs(curr),yy);
		for(long curr: y)
			count+=counter(abs(curr),xx);
		if(xx.find(0)!=xx.end())
			count+=(n-1)*m;
		else if(yy.find(0)!=yy.end())
			count+=(m-1)*n;
		printf("%ld\n",count);
	}
}
