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
		int n, sm;
		cin>>n>>sm;
		vector<int> pre(n + 1);
		for(int i=0;i<n;i++) {
			int x;
			cin>>x;
			pre[i+1] = pre[i] + x;
		}
		if(pre[n] < sm) {
			cout<<"-1\n";
			continue;
		}
		int result = n;
		for(int i = binary_search(pre.begin(),pre.end(),sm); i <= n; i++) {
			int p = lower_bound(pre.begin(), pre.end(), pre[i] - sm) - pre.begin();
			result = min(result, n - (i - p));
		}
		cout<<result<<"\n";
	}
}