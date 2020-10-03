#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long res = 0, r, k;
		scanf("%d%ld",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%ld",&r),res+=r;
		printf("%ld\n",res%k);
	}
}
