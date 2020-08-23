#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	s1 = " " + s1;
	s2 = " " + s2;
	int row = s1.size();
	int col = s2.size();
	vector<vector<int>> mat(row, vector<int> (col,0));
	for(int i=0;i<row;i++)
		mat[i][0] = 1;
	for(int i=0;i<col;i++)
		mat[0][i] = 1;
	for(int i=1;i<row;i++)
	{
		for(int j=1;j<col;j++)
		{
			if(s1[i]==s2[j])
			{
				mat[i][j] = 1 + mat[i-1][j-1];
			}
			else
			{
				mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
			}
		}
	}
	/*cout<<"  ";
	for(char c: s2)
		cout<<c<<' ';
	cout<<'\n';
	for(int i=0;i<row;i++)
	{
		cout<<s1[i]<<' ';
		for(int j=0;j<col;j++)
			cout<<mat[i][j]<<' ';
		cout<<'\n';
	}*/
	int i = row -1;
	int j = col -1;
	string res = "";
	while(mat[i][j]!=1)
	{
		if(mat[i][j] == mat[i-1][j])
			i--;
		else if(mat[i][j] == mat[i][j-1])
			j--;
		else if(mat[i][j] == mat[i-1][j-1] + 1)
		{
			res += s1[i];
			i--;
			j--;
		}
		else
		{
			if(mat[i-1][j] > mat[i][j-1])
				j--;
			else
				i--;
		}
	}
	reverse(res.begin(),res.end());
	cout<<res<<'\n';
}
