#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		double s = (a+b+c+d);
		if((long long)s%3==0 && s/3>=a && s/3>=b && s/3>=c)
			cout<<"YES\n";
		else
			cout<<"NO\n";	
	}
}
