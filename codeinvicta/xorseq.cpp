#include<bits/stdc++.h>
using namespace std;

long xorr(long l)
{
	long r = 0;
	if(l%4 == 0)
		r = l;
	else if(l%4 == 1)
		r = 1;
	else if(l%4 == 2)
		r = l + 1;
	else
		r = 0;
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	long n;
	cin>>n;
	set<long> s,s1;
	long x1,x2,q;
	s.insert(n+1);
	cin>>q;
	while(q--)
	{
		cin>>x1>>x2;
		if(x1 == 1)
		{
			auto it = s1.find(x2);
			if(it != s1.end())
				s1.erase(it);
			s.insert(x2);
			if(s.find(x2-1) == s.end())
				s1.insert(x2-1);
			if(s.find(x2+1) == s.end())
				s1.insert(x2+1);
		}
		else
		{
		
			long l;
			if(s.find(x2)==s.end() || s1.find(x2) !=s1.end())
				l = x2;
			else
				l = *s1.upper_bound(x2);
			long r = *s.upper_bound(l);
			printf("%ld\n",xorr(r-1)^xorr(l-1));
		}
	}
	return 0;
}
