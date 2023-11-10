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
		int n, m, k;
		cin>>n>>m>>k;
		map<int,int> counter;
		for(int i=0;i<n;i++) {
			int x;
			cin>>x;
			counter[x]++;
		}
		int mn = 0, mx = 0;
		bool isPossible = true;
		for(int i=k-1;i>=0;i--) {
			if(counter.count(i)) {
				mx += counter[i];
				mn++;
			} else {
				isPossible = false;
				break;
			}
		}

		for(int i=k+1;i<=100;i++) {
			if(mn >= m)
				break;
			if(counter.count(i)) {
				mx += counter[i];
				mn ++;
			}
		}
		puts(isPossible && mn >= k && mn <= m && mx >= m ? "YES" : "NO");
	}
}