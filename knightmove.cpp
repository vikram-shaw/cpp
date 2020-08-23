#include<bits/stdc++.h>
using namespace std;
int solve(long r,long c)
{
		if(r + c == 0)return 0;
		if(r + c == 1)return 3;
		if(r == 2 && c == 2)return 4;
		
		long step = max((r+1)/2, (c+1)/2);
		step = max(step, (r+c+2)/3);
		step += (step^r^c)&1;
		return step;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
    	int a,b;
    	cin>>a>>b;
        cout<<solve(a-1,b-1)<<endl;
	}
}
