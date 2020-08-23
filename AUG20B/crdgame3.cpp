#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long long pc, pr;
	cin>>pc>>pr;
	if(ceil(pc/9.0) < ceil(pr/9.0))
		cout<<"0 "<<ceil(pc/9.0)<<'\n';
	else
		cout<<"1 "<<ceil(pr/9.0)<<'\n';
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",i);
        solve();
	}
}
