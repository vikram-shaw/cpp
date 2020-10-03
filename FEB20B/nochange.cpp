#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p,i;
		scanf("%d%d",&n,&p);
		vector<int> D(n),coin(n);
		for(int &x: D)
			scanf("%d",&x);
		for(i=n-1;i>=0;i--)
		{
			if(p%D[i]==0)
				coin[i] = p/D[i] - 1;
			else
				coin[i] = p/D[i] + 1;
			p -= coin[i]*D[i];
			if(p<0)
				break;
		}
		if(i==-1)
			puts("NO");
		else
		{
			printf("YES");
			for(i=0;i<n;i++)
				printf(" %d",coin[i]);
			printf("\n");
		}
	}
}
