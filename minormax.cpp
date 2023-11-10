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
		freopen("log.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> b(n);
		for(int i=0;i<n;i++) {
			cin>>b[i];
		}
		int mn, mx;
		mn = mx = b[0];
		bool isPossible = true;
		for(int i=1;i<n;i++) {
			if(mx > b[i] && mn < b[i]) {
				isPossible = false;
				break;
			}
			mx = max(mx, b[i]);
			mn = min(mn, b[i]);
		}
		puts(isPossible ? "YES" : "NO");
	}
}
