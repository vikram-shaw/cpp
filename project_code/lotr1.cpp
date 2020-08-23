#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin>>m>>n;
		long long curr = 0, mul = 0;
		while(curr <= n)
		{
			mul++;
			curr = stoll(to_string(curr) + "9");
		}
		mul--;
		cout<<mul*m<<' '<<m<<'\n';
	}
}
