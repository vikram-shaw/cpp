#include<bits/stdc++.h>
using namespace std;

bool matrix[1001][1001];
short dp[1001][1001];

int n, m;

bool create(int i, int j)
{
	if((i == 0 && j < 0) || (i < 0 && j == 0))
		return true;
	if(i < 0 || j < 0)
		return false;
	if(dp[i][j] != -1)
		return dp[i][j] == 1;
	if(matrix[i][j] == false)
	{
		dp[i][j] = 0;
		return false;
	}
	bool left = create(i-1,j);
	bool right = create(i,j-1);
	dp[i][j] = left || right;
	return dp[i][j] == 1;
}

bool is_possible(int i, int j)
{
	if((i == 0 && j < 0) || (i < 0 && j == 0))
		return true;
	if(i < 0 || j < 0 || i >= n || j >= m)
		return false;
	if(dp[i][j] != -1)
		return dp[i][j] == 1;
	return is_possible(i-1,j) || is_possible(i,j-1);
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<m;j++)
			matrix[i][j] = s[j] == '#' ? false : true;
	}
	
	memset(dp,-1,sizeof(dp));
	create(n-1,m-1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			int temp = dp[i][j];
			if(is_possible(n,m))
				cout<<"1 ";
			else
				cout<<"0 ";
			dp[i][j] = temp;
		}
		puts("");
	}
}
