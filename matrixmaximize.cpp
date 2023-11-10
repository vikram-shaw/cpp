#include<bits/stdc++.h>
using namespace std;

int dp[2505][500];

int rec(int total, vector<pair<int,int>>& v, int c) {
	if(total <= 0 || c == -1)
		return 0;
	if(dp[c][total] != -1)
		return dp[c][total];
	int include = 0;
	if(v[c].second <= total)
		include = v[c].first + rec(total - v[c].second, v, c - 1);
	int exclude = rec(total, v, c - 1);
	return dp[c][total] = max(include, exclude);
}

int main() {
	memset(dp,-1,sizeof(dp));
	int n, m;
	cin>>n>>m;
	int x, y, total;
	cin>>x>>y>>total;
	vector<pair<int,int>> v(n*m);
	int k = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>v[k].first;
			v[k++].second = (abs(x - i) + abs(y - j)) * 2 + 1;
		}
	}
	cout<<rec(total, v, n * m - 1)<<"\n";
}