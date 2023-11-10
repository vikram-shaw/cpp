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
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) {
		cin>>v[i];
	}
	int count = 0;
	while(true) {
		bool found = false;
		vector<int> nv;
		vector<bool> remove(n);
		for(int i=n-1;i>=1;i--) {
			if(v[i-1] > v[i]) {
				found = true;
				remove[i] = true;
			}
		}
		if(!found) {
			break;
		}
		count++;
		for(int i=0;i<n;i++) {
			if(!remove[i]) {
				nv.push_back(v[i]);
			}
		}
		n = nv.size();
		v = nv;
	}
	cout<<count<<"\n";
}