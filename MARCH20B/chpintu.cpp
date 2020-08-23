#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,r;
		cin>>n>>m;
		int F[n];
		map<int,int> map;
		for(int i=0;i<n;i++)
			scanf("%d",F+i);
		for(int i=0;i<n;i++)
			scanf("%d",&r),map[F[i]]+=r;
		int result = 0x3f3f3f3f;
		for(pair<int,int> p: map)
		{
			if(p.second<result)
				result = p.second;
		}
		printf("%d\n",result);
	}
}
