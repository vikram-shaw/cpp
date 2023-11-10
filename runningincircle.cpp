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
	for(int ii=1;ii<=t;ii++) {
		long long l, n, sm = 0, count = 0;
		cin>>l>>n;
		for(int i=0;i<n;i++) {
			long long x;
			char c;
			cin>>x>>c;
			sm += (c == 'C' ? x : -x);
			if(sm >= l || sm <= l) {
				long absum = abs(sm);
				count += absum / l;
			}
			sm %= l;
		}
		cout<<"Case #"<<ii<<": "<<count<<"\n";
	}
}