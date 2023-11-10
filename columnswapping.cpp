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
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>v[i][j];
			}
		}
		set<int> s[n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m-1;j++) {
				if(v[i][j] > v[i][j+1]) {
					s[i].insert(j);
				}
			}
		}
		bool isSame = true;
		int size = s[0].size();
		for(int i=0;i<n;i++) {
			if(s[i].size() != size) {
				isSame = false;
				break;
			}
		}
		if(!isSame) {
			puts("-1");
		}
		else if(size == 2) {
			for(int x: s[0]) {
				cout<<x + 1<<" ";
			}
			puts("");
		} else if(size < 2) {
			puts("1 1");
		} else {
			puts("-1");
		}
	}
}