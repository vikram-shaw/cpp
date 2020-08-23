#include<bits/stdc++.h>
using namespace std;
#define google
const int MOD = 1000000007;
namespace math
{
	int pow(int x,int n)	// to calculate pow(x,n)%MOD
	{
		if(n==0)
			return 1;
		if(n%2)
			return (x%MOD*math::pow(x,n-1)%MOD)%MOD;
		int value = math::pow(x,n/2)%MOD;
		return (value*value)%MOD;
	}
	
	template<typename T>
	T lcm(T x,T y)
	{
		return x*y/__gcd(x,y);
	}
	//ncr
}

void solve(int t)
{
	#ifdef google
		cout<<"Case #"<<t<<": ";
	#endif
	cout<<(5*math::pow(5,MOD-2)%MOD)%MOD<<'\n';
}

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
		solve(i);
}
