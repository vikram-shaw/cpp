#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	bool b = false;
	for(int i=0;i<n;i++)
	{
		int r;
		cin>>r;
		if(r%2==0)
		{
			b = true;
		}
	}
	if(!b)
		puts("YES");
	else
		puts("NO");
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
