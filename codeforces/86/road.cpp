#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long long a,b,x,y;
	cin>>x>>y>>a>>b;
	long long mn = min(x,y);
	long long res = min(b*mn,2*a*mn);
	if(x==mn){
		y -= x;
		x = y;
	}
	else{
		x -= y;
	}
	res += x*a;
	cout<<res<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",t);
        solve();
	}
}
