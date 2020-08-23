#include<bits/stdc++.h>
using namespace std;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int bits[51];
int a[51];

void genbit()
{
	for(int i=0;i<=50;i++)
	{
		int result = 0;
		int num = i;
		for(int j=0;j<15;j++)
			if(num%prime[j] == 0)
				result |= (1<<j);
		bits[num] = result;
	}
}

int dp[51][100000];
int rec(int n, int s = 0)
{
	if(n == -1)
		return 0;
	if(dp[n][s] != -1)
		return dp[n][s];
	int can_be_taken = true;
	int num = bits[a[n]];
	for(int i=0;i<15;i++)
	{
		if(((num>>i)&1) == 1 && ((s>>i)&1) == 1)
		{
			can_be_taken = false;
			break;
		}
	}
	if(can_be_taken)
		return dp[n][s] = max(rec(n-1,s),1+rec(n-1,s|num));
	return dp[n][s] = rec(n-1,s);
}

int main()
{
	genbit();
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<rec(n-1)<<'\n';
}
