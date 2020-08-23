#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& lwh, vector<vector<int>>& disk)
{
	sort(lwh.begin(),lwh.end());
	do
	{
		disk.push_back(lwh);
	}while(next_permutation(lwh.begin(),lwh.end()));
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<vector<int>> disk;
		vector<int> lwh(3);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
				cin>>lwh[j];
			insert(lwh,disk);
		}
		
		int l = disk.size();
		
		sort(disk.begin(),disk.end(),[](const vector<int>& v1, const vector<int>& v2){
			if(v1[1] == v2[1])
				return v1[0] < v2[0];
			return v1[1] < v2[1];
		});
		vector<vector<int>> tem(disk.begin(),disk.end());
		sort(tem.begin(),tem.end(),[](const vector<int>& v1, const vector<int>& v2){
			if(v1[0] == v2[0])
				return v1[1] < v2[1];
			return v1[0] < v2[0];
		});
		
		for(int i=0;i<l;i++)
			disk.push_back(tem[i]);
		l = 2*l;
		
		vector<int> dp(l);
		for(int i=0;i<l;i++)
			dp[i] = disk[i][2];
		int res = 0;
		for(int i=1;i<l;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(disk[j][0] < disk[i][0] && disk[j][1] < disk[i][1])
				{
					dp[i] = max(dp[i],dp[j] + disk[i][2]);
					res = max(res,dp[i]);
				}
			}
		}
		cout<<res<<endl;
	}
}
