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
		int n, q;
		cin>>n>>q;
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			cin>>v[i];
		}
		sort(v.rbegin(),v.rend());
		vector<int> prefix(n+1);
		for(int i=0;i<n;i++) {
			prefix[i+1] = prefix[i] + v[i];
		}
		while(q--) {
			int x;
			cin>>x;
			vector<int>::iterator index = lower_bound(prefix.begin(),prefix.end(),x);
			if(index == prefix.end())
				puts("-1");
			else
				cout<<(index - prefix.begin())<<"\n";
		}
	}
}