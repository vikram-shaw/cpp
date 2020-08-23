#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int k,i;
	cin>>k;
	cout<<"O";
	
	for(i=2;i<=k && i<=64;i++)
	{
		cout<<".";
		if(i%8==0)
			puts("");
	}
	for(;i<=64;i++)
	{
		cout<<"X";
		if(i%8==0)
			puts("");
	}
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
/*
O....X..
XXXXXX.. 
........
........
........
........
........
........
 */
