/*******************
 ****VIKRAM SHAW****
********************/
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
	#define log(x) cerr << #x << " "; _print(x); cerr << endl;
#endif
#ifdef ONLINE_JUDGE
	#define log(x)
#endif

template<typename T> void _print(T argument) { cerr << argument; }
template<typename K, typename V> void _print(pair<K,V> x) { cerr << "{ " << x.first << " -> " << x.second << " }"; }
template<class T> void _print(vector<T> v) { cerr << "[ "; for(T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(set<T> v) { cerr << "[ "; for(T i: v) { _print(i); cerr << " "; } cerr << "]"; }
template<class K, class V> void _print(map<K,V> v) { cerr << "[ "; for(pair<K,V> i: v) { _print(i); cerr << " "; } cerr << "]";}

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
	#ifndef ONLINE_JUDGE
		freopen("error.txt","w",stderr);
	#endif
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