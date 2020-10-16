#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int dp[5][n+1];
	
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=n;i++)
		dp[0][i] = i;
	
	int coin[] = {1,5,7,9,11};
	
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j<coin[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = min(dp[i-1][j],1+dp[i][j-coin[i]]);
		}
	}
	cout<<(dp[4][n])<<endl;
}
