#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int main()
{
	int n,m;
	cin>>n>>m;
	int grid[n][n];
	memset(grid,0,sizeof(grid));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<m;i++)
	{
		int r,c;
		cin>>r>>c;
		r--;
		c--;
		grid[r][c] = 1;
	}
	if(grid[0][0])
		dp[0][0] = 1;
	for(int i=1;i<n;i++)
	{
		dp[i][0] = dp[i-1][0] + grid[i][0];
		dp[0][i] = dp[0][i-1] + grid[0][i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j];
		}
	}
	int res = 0;
	puts("first\tsecond\tthird\tforth\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int first, second, third, forth;
			first = dp[i][j];
			second = dp[i][n-1] - dp[i][j];
			third = dp[n-1][j] - dp[i][j];
			forth = dp[n-1][n-1] - first - second - third;
			res = max(res,min(first,min(second,min(third,forth))));
			cout<<first<<'\t'<<second<<'\t'<<third<<'\t'<<forth<<endl;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}
	cout<<res<<endl;
}

