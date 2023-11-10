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

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		int n, m;
		cin>>n>>m;
		vector<vector<int>> v(n, vector<int>(m));
		map<int,int> rightleft, leftright;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>v[i][j];
				rightleft[i+j] += v[i][j];
				leftright[i-j] += v[i][j];
			}
		}
		log(leftright);
		// log(rightleft);
		int result = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				result = max(result, leftright[i-j] + rightleft[i+j] - v[i][j]);
			}
		}
		cout<<result<<"\n";
	}
}