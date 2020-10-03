#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int main()
{
	long n,w;
	cin>>n>>w;
	long value[n], weight[n];
	long sum = 0;
	for(long i=0;i<n;i++)
		cin>>weight[i]>>value[i],sum+=value[i];
	vector<long> dp(sum+1,INF);
	dp[0] = 0;
	for(long item=0;item<n;item++)
	{
		for(long already_value = sum - value[item]; already_value>=0; --already_value)
		{
			dp[already_value + value[item]] = min(dp[already_value + value[item]], dp[already_value] + weight[item]);
		}
	}
	long result = 0;
	for(long i=0;i<=sum;i++)
	{
		if(dp[i]<=w)
			result = max(result,i);
	}
	printf("%ld\n",result);
}
