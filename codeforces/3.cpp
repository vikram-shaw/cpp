#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a=0,b=0,c=0;
		cin>>n;
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0)
			{
				if(a==0){
					a = i;
					n = n/i;
				}
				else if(b==0){
					if(i == n/i || i==a || n/i == a)
						continue;
					b = n/i;
					c = i;
					break;
				}
			}
		}
		if(a==0 || b==0 || c==0)
			cout<<"NO\n";
		else
			cout<<"YES\n"<<a<<' '<<c<<' '<<b<<'\n';
	}
}
