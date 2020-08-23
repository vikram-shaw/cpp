#include<bits/stdc++.h>
using namespace std;

bool matrix[1001][1001];
short dp[1001][1001];

int n, m;

bool is_possible(int i, int j)
{
	if((i == 0 && j < 0) || (i < 0 && j == 0))
		return true;
	if(i < 0 || j < 0)
		return false;
	if(dp[i][j] != -1)
		return dp[i][j]?true:false;
	if(matrix[i][j] == false)
	{
		dp[i][j] = 0;
		return false;
	}
	dp[i][j] = is_possible(i-1,j) || is_possible(i,j-1);
	return dp[i][j]?true:false;
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
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			memset(dp,-1,sizeof(dp));
			matrix[i][j] = !matrix[i][j];
			if(is_possible(n-1,m-1))
				cout<<"1 ";
			else
				cout<<"0 ";
			matrix[i][j] = !matrix[i][j];
			
		}
		puts("");
	}
}
