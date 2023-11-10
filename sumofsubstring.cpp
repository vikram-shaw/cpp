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
		long long n, k;
		string s;
		cin>>n>>k>>s;
		long long f = -1, l = -1;
		for(int i=0;i<n;i++) {
			if(s[i] == '1') {
				l = i;
				if(f == -1) {
					f = i;
				}
			}
		}
		if(l != -1 && n - l - 1 <= k) {
			swap(s[l], s[n-1]);
			k -= (n - l - 1);
		}
		if(f != -1 && f != n - 1 && f <= k) {
			swap(s[f], s[0]);
		}
		long long result = 0;
		for(int i=0;i<n-1;i++) {
			result += (((s[i] - '0') * 10) + (s[i+1] - '0'));
		}
		log(s);
		cout<<result<<"\n";
	}
}