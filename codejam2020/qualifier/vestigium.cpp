#include<bits/stdc++.h>
using namespace std;

void solve(int t)
{
    printf("Case #%d: ",t);
    int n;
    scanf("%d",&n);
    vector<vector<int>> matrix(n,vector<int>(n));
    int trace = 0, row = 0, column = 0;
    for(int i=0;i<n;i++)
    {
		for(int j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]);
			if(i == j)
				trace += matrix[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		set<int> repeat;
		for(int j=0;j<n;j++)
		{
			if(repeat.find(matrix[i][j])!=repeat.end())
			{
				column++;
				break;
			}
			repeat.insert(matrix[i][j]);
		}
	}
	for(int j=0;j<n;j++)
	{
		set<int> repeat;
		for(int i=0;i<n;i++)
		{
			if(repeat.count(matrix[i][j]))
			{
				row++;
				break;
			}
			repeat.insert(matrix[i][j]);
		}
	}
	printf("%d %d %d\n",trace,column,row);
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
