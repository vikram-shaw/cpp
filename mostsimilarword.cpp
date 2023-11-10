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

int mininum(string s1, string s2) {
	int diff = 0;
	for(int i=0;i<s1.length();i++) {
		diff += abs(s1[i] - s2[i]);
	}
	return diff;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		int n, m;
		cin>>n>>m;
		vector<string> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		int result = 0x3f3f3f3f;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				result = min(result, mininum(v[i],v[j]));
			}
		}
		cout<<result<<"\n";
	}
}