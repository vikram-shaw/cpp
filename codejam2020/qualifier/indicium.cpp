#include<bits/stdc++.h>
using namespace std;

void solve(int t)
{
    printf("Case #%d: ",t);
    int n,k;
    scanf("%d%d",&n,&k);
    if(k%n==0)
    {
		puts("POSSIBLE");
		vector<vector<int>> matrix(n,vector<int>(n));
		int diagonal = k/n;
		for(int i=0;i<n;i++)
			matrix[i][i] = diagonal;
		int c=1;
		for(int i=1;i<n;i++)
		{
			int p = i;
			int q = 0;
			if(diagonal == c)
				c++;
			for(;p>=0;p--,q++)
			{
				if(p == q)
					continue;
				matrix[p][q] = c;
			}
			c++;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				matrix[n-1-i][n-1-j] = matrix[i][j];
				matrix[n-1-j][n-1-i] = matrix[i][j];
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%d ",matrix[i][j]);
			puts("");
		}
	}
	else
		puts("IMPOSSIBLE");
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);
}
