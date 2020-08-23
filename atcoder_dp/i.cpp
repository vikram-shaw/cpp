#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<double> dp(n+1);
	dp[0] = 1;
	for(int i=0;i<n;i++)
	{
		double r;
		scanf("%lf",&r);
		for(int j=i+1;j>=0;j--)
		{
			dp[j] = (j==0?0:dp[j-1]*(r)) + dp[j]*(1-r);
		}
	}
	double result = 0;
	for(int i=n/2+1;i<=n;i++)
		result+=dp[i];
	printf("%.10lf\n",result);
}
