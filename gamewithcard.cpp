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

string solve(bool aliceChance, vector<int> a, vector<int> b) {
	if(aliceChance) {
		if(a.back() >= b.back()) {
			return "Alice";
		} else {
			return "Bob";
		}
	} else {
		if(a.back() <= b.back()) {
			return "Bob";
		} else {
			return "Alice";
		}
	}
	return "empty";
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		int n, m;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		cin>>m;
		vector<int> b(m);
		for(int i=0;i<m;i++) {
			cin>>b[i];
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		cout<<solve(true,a,b)<<"\n";
		cout<<solve(false,a,b)<<"\n";
	}
}