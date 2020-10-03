#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int h,p;
	cin>>h>>p;
	bool chef = true;
	for(int i=1;i<18;i++)
	{
		h -= p;
		p >>= 1;
		if(h <= 0)
			break;
		if(p == 0)
		{
			chef = false;
			break;
		}
	}
	if(chef)
		puts("1");
	else
		puts("0");
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
