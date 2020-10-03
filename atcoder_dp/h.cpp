#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9+7;

void self_add(int& a, int b)
{
	a += b;
	if(a >= MOD)
		a%=MOD;
}

int main()
{
	int H,W;
	cin>>H>>W;
	vector<vector<char>> mat(H,vector<char>(W));
	vector<vector<int>> dp(H,vector<int>(W));
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			cin>>mat[i][j];
	dp[0][0] = 1;
	for(int i=1;i<H;i++)
		if(mat[i][0] == '.')
			dp[i][0] = dp[i-1][0];
		else
			break;
	for(int i=1;i<W;i++)
		if(mat[0][i] == '.')
			dp[0][i] = dp[0][i-1];
		else
			break;
	for(int i=1;i<H;i++)
		for(int j=1;j<W;j++)
			if(mat[i][j]=='.')
				self_add(dp[i][j], dp[i-1][j] + dp[i][j-1]);
	cout<<dp[H-1][W-1]%MOD<<'\n';
}
